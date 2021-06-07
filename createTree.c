
#include "tree.h"

//This functions initializes the information about a file/directory
node* createTreeNode(char *name) {
    node* nn = (node*)malloc(sizeof(node));
    nn->fname = name;
    nn->isdir = 1;
    nn->isrootNode = 0;
    
    nn->info.fsize = 0;
    
    nn->info.fpath = (char*)calloc(1000, sizeof(char));
    nn->info.fpermissions = (char*)calloc(11, sizeof(char));
    nn->info.fuser_name = (char*)calloc(30, sizeof(char));
    
    //last modification details
    nn->info.last_mod.fdate = -1;
    nn->info.last_mod.fmon = -1;
    nn->info.last_mod.fyear = -1;
    nn->info.last_mod.fhour = -1;
    nn->info.last_mod.fmin = -1;
    nn->info.last_mod.fsec = -1;
    
    //self referencial pointers
    nn->inner_ptr = NULL;
    nn->next_ptr = NULL;
    
    return nn;
}

node* createTree(char *rootname) {
	DIR *dir = opendir(rootname);
	//if it fails to open root directory then return
    if(!dir) {
        printf("Failed to open %s ...", rootname);
        return NULL;
    }
	closedir(dir);
	
	node *rootNode = createTreeNode(rootname);
	rootNode->isrootNode = 1;
	rootNode->inner_ptr = createTree_1(rootname);
	rootNode->info.fpath = ".";
	return rootNode;
}

node* createTree_1(char *rootname) {
    node *p = NULL, *q = NULL;
    node *t_start = NULL;
    
    char name[1000];
    struct dirent *dr = NULL;
    
    //opening a directory 
    DIR *dir = opendir(rootname);
    if(!dir) {
        printf("Failed to open %s...\n", rootname);
        return NULL;
    }
	
	//traversing until end of directory stream
    while((dr = readdir(dir)) != NULL) {
    	
    	//Not to consider sub-directories "." and ".."
    	if(strcmp((dr->d_name),".") != 0 && strcmp((dr->d_name),"..") != 0) 
			p = createTreeNode(dr->d_name);
		else {
			p = NULL;
			continue;
		}
    
        //t_start will point to first node in root directory
        if(!q)
            t_start = p;
        else
            q->next_ptr = p;
        
		//if current stream is directory
        if((dr->d_type) == DT_DIR) {
            p->isdir = 1;
            strcpy(name, rootname);
            
            p->inner_ptr = createTree_1(strcat((strcat(name, "/")), dr->d_name));
            p->info.fsize = get_Size(name);
            p->info.inode = get_inode(name);
            strcpy(p->info.fpermissions, get_permissions(name));
            //printf("%s\n", name);
            strcpy(p->info.fpath, name);
            strcpy(p->info.fuser_name, get_username(name));
		 	get_last_mod(p, name);
            
            strcpy(name, rootname);
            
        }	//else current stream is not directory
        else {
            p->isdir = 0;
            p->inner_ptr = NULL;
            
            strcpy(name, rootname);
            strcat((strcat(name, "/")), dr->d_name);
            p->info.fsize = get_Size(name);
            
            //printf("%s\n", name);
            p->info.inode = get_inode(name);
            strcpy(p->info.fpath, name);
            strcpy(p->info.fuser_name, get_username(name));
            strcpy(p->info.fpermissions, get_permissions(name));
            get_last_mod(p, name);
            strcpy(name, "");		
        }
        
        q = p;
    }
    
    //returning start node of tree structure
    return t_start;

}

//get the size of directory using stat()
unsigned long int get_Size(char *file_name) {
	struct stat st;		//declare stat variable
	
	if(stat(file_name, &st) == 0)
		return st.st_size;
	else
		return 0;
}

//get the size of file using fseek() and ftell()
long int get_fileSize(char *file_path) {
	FILE *fp = fopen(file_path, "r");
	if(!fp) {
		return -1;
	}
	long int size;
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fclose(fp);
	return size;
}

//get the inode number of file using stat()
long int get_inode(char *file_name) {
	struct stat st;
	if(stat(file_name, &st) == 0)
		return st.st_ino;
	else
		return 0;
}

//get file type and permissions
char per[11];
char* get_permissions(char *file_name) {
	struct stat st;
	if(lstat(file_name, &st) != 0)
		return NULL;
	
	char *s = per; 
	
	if(S_ISREG(st.st_mode))
    	*s = '-';
  	else if(S_ISDIR(st.st_mode))
    	*s = 'd';
  	else if(S_ISCHR(st.st_mode))
    	*s = 'c';
  	else if(S_ISBLK(st.st_mode))
    	*s = 'b';
  	else if(S_ISFIFO(st.st_mode))
    	*s = 'f';
  	else if(S_ISLNK(st.st_mode))
    	*s = 'l';
  	else if(S_ISSOCK(st.st_mode))
    	*s = 's';
    
    s++;
    
    mode_t owner, group, other;
    
    owner = st.st_mode & S_IRWXU;
  	group = st.st_mode & S_IRWXG;
  	other = st.st_mode & S_IRWXO;
  	
  	*s++ = owner & S_IRUSR ? 'r' : '-';
  	*s++ = owner & S_IWUSR ? 'w' : '-';
  	*s++ = owner & S_IXUSR ? 'x' : '-';

  	*s++ = group & S_IRGRP ? 'r' : '-';
  	*s++ = group & S_IWGRP ? 'w' : '-';
  	*s++ = group & S_IXGRP ? 'x' : '-';

  	*s++ = other & S_IROTH ? 'r' : '-';
  	*s++ = other & S_IWOTH ? 'w' : '-';
  	*s++ = other & S_IXOTH ? 'x' : '-';

  	*s = '\0';
  	
  	return per;
}

//get last modification time details using struct stat and tm
void get_last_mod(node* ptr, char *file_name) {
	struct stat st;
	struct tm *mod;
	
	if(stat(file_name, &st) != 0)
		return;
	
	mod = localtime(&st.st_mtime);


	ptr->info.last_mod.fdate = mod->tm_mday;
	ptr->info.last_mod.fmon = mod->tm_mon + 1;
	ptr->info.last_mod.fyear = mod->tm_year + 1900;
	ptr->info.last_mod.fhour = mod->tm_hour;
	ptr->info.last_mod.fmin = mod->tm_min;
	ptr->info.last_mod.fsec = mod->tm_sec;
	return;
}

//To get the username of file
char* get_username(char* file_name) {
	struct stat st;
	stat(file_name, &st);
	struct passwd *pwuser;
	pwuser = getpwuid(st.st_uid);
	return pwuser->pw_name;

}

//when --help flag is used
void help(char *file_name) {
	FILE *fp = fopen(file_name, "r");
	if(!fp) {
		return;
	}
	
	char c = fgetc(fp);
	while(c != EOF) {
		printf("%c", c);
		c = fgetc(fp);
	}
	return;
}

