
#include "tree.h"

//creating tree structure according to pattern specified
node* createPatternTree(char *rootname, char *pattern, char *flag) {
	node *rootNode = createTreeNode(rootname);
	rootNode->isrootNode = 1;
	rootNode->inner_ptr = createPatternTree_1(rootname, pattern, flag);
	rootNode->info.fpath = ".";
	return rootNode;
}

node* createPatternTree_1(char *rootname, char *pattern, char *flag) {
    node *p = NULL, *q = NULL;
    node *t_start = NULL;
    
    char name[1000];
    struct dirent *dr = NULL;
    DIR *dir = opendir(rootname);
    if(!dir) {
        printf("Failed to open %s...\n", rootname);
        return NULL;
    }
    int k;
	
    while((dr = readdir(dir)) != NULL) {
    	
    	//match_pattern() returns 1 when pattern is matched, otherwise returns 0
    	if(!strcmp(flag, "-P"))
			k = match_pattern(dr->d_name, pattern);
		else if(!strcmp(flag, "-I"))
			k = !match_pattern(dr->d_name, pattern);
		
		//traversing only 
    	if((dr->d_type) == DT_DIR || k) {
			if(strcmp((dr->d_name),".") != 0 && strcmp((dr->d_name),"..") != 0) {
				p = createTreeNode(dr->d_name);
		}
		else {
			p = NULL;
			continue;
		}
		
		    
		if(!q)
			t_start = p;
		else
		    q->next_ptr = p;
		    

		if((dr->d_type) == DT_DIR) {
		        p->isdir = 1;
		        strcpy(name, rootname);
		        
		        p->inner_ptr = createPatternTree_1(strcat((strcat(name, "/")), dr->d_name), pattern, flag);
		        p->info.fsize = get_Size(name);
		        p->info.inode = get_inode(name);
		        strcpy(p->info.fpermissions, get_permissions(name));
		        //printf("%s\n", name);
		        strcpy(p->info.fpath, name);
		        strcpy(p->info.fuser_name, get_username(name));
			 	get_last_mod(p, name);
		        
		        strcpy(name, rootname);
		        
		}
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
    }
    return t_start;

}

//This functions returns 1 when wild-card pattern is matched , returns 0 when not matched
int match_pattern(char *str, char *patt) {
    int st_len = strlen(str);
    int pat_len = strlen(patt);
    
    //2-D array with row_number = pattern length + 1 and column_number = string length + 1 
    int arr[pat_len+1][st_len+1];
    
    int i, j;
    for(i = pat_len; i >= 0; i--) {
        for(j = st_len; j >= 0; j--) {
        	//last cell will be set to 1 as blank character in pattern matches with blank character in string
            if(i == pat_len && j == st_len) {
                arr[i][j] = 1;
            }
            else if(i == pat_len) {		//blank character of pattern won't match with non-blank characters in string
                arr[i][j] = 0;
            }
            else if(j == st_len) {		//'*' character in pattern will look for below and next row cells 
                if(patt[i] == '*')				// otherwise will be 0
                    arr[i][j] = arr[i+1][j];
                else
                    arr[i][j] = 0;
            }
            else {
                if(patt[i] == '?')		// '?' looks for next diaginal entry
                    arr[i][j] = arr[i+1][j+1];
                else if(patt[i] == '*')		// '*' will be logical OR of below cell and next cell entry
                    arr[i][j] = arr[i+1][j] || arr[i][j+1];
                else if(patt[i] == str[j])		// when other character matches then look for next diaginal entry
                    arr[i][j] = arr[i+1][j+1];
                else
                    arr[i][j] = 0;			// when other character does not match then cell will be 0

            }
        }
    }
    
    //returning entry at first cell (0th row 0th column)
    return arr[0][0];

}


