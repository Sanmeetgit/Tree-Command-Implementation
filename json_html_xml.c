
#include "tree.h"

//when -J flag is used (to print json formatted array) 
void printTree_J(tnode t) {
	node *p = t;
	int i;
	
	char *space = "     ";
    if(!p)
        return;
    
    if(p->isrootNode || p->fname[0] != '.') {

		if(count >= 0 && !p->isrootNode) {
			printf("%s", space);
		}
		
		//checking for directory or file
		if(p->isdir) {
			for(i = 0; i < count; i++) {    	
				printf("%s", space);
			}
			
			//checking for root directory or not
			if(p->isrootNode)
				printf("[{\"type\":\"directory\",\"name\" :\"%s\",\"contents\":[\n", p->fname);
			else
				printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", p->fname);
			
		}
		else {
			for(i = 0; i < count; i++) {    	
				printf("%s", space);
			}
			if(p->next_ptr)
				printf("{\"type\":\"file\",\"name\":\"%s\"},\n", p->fname);
			else 
				printf("{\"type\":\"file\",\"name\":\"%s\"}\n", p->fname);
			
		}
		
		if(p->isdir) {
			if(p->isrootNode) {
				printTree_J(p->inner_ptr);
				for(i = 0; i < count; i++) {    	
					printf("%s", space);
				}
				printf("  ]},\n  {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n", dir_count, file_count);
				printf("]\n");
			}
			else {
				//incrementing directory count
				dir_count++;
				count++;
				printTree_J(p->inner_ptr);
				for(i = 0; i < count; i++) {    	
					printf("%s", space);
				}
				if(p->next_ptr)
					printf("]},\n");
				else
					printf("]}\n");
				count--;
			}
		} 
		if(!p->isdir)
    		file_count++;		//incrementing file count
    }
    
    printTree_J(p->next_ptr);
    
    return;

}

//when -J -o used to send json output to file 
void printTree_Jo(FILE *fp, tnode t) {
	node *p = t;
	int i;
	char *space = "     ";
    if(!p)
        return;
    
    if(p->isrootNode || p->fname[0] != '.') {
		if(count >= 0 && !p->isrootNode) {
			fprintf(fp, "%s", space);
		
		}
		
		//checking for directory or file
		if(p->isdir) {
		
			for(i = 0; i < count; i++) {    	
				fprintf(fp, "%s", space);
			}
			if(p->isrootNode)
				fprintf(fp, "[{\"type\":\"directory\",\"name\" :\"%s\",\"contents\":[\n", p->fname);
			else
				fprintf(fp, "{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", p->fname);
			
		}
		else {
			for(i = 0; i < count; i++) {    	
				fprintf(fp, "%s", space);
			}
			if(p->next_ptr)
				fprintf(fp, "{\"type\":\"file\",\"name\":\"%s\"},\n", p->fname);
			else 
				fprintf(fp, "{\"type\":\"file\",\"name\":\"%s\"}\n", p->fname);
			
		}
		
		if(p->isdir) {
			if(p->isrootNode) {
				printTree_Jo(fp, p->inner_ptr);
				for(i = 0; i < count; i++) {    	
					fprintf(fp, "%s", space);
				}
				fprintf(fp, "  ]},\n  {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n", dir_count, file_count);
				fprintf(fp, "]\n");
			}
			else {
				dir_count++;
				count++;
				printTree_Jo(fp, p->inner_ptr);
				for(i = 0; i < count; i++) {    	
					fprintf(fp, "%s", space);
				}
				if(p->next_ptr)
					fprintf(fp, "]},\n");
				else
					fprintf(fp, "]}\n");
				count--;
			}
		} 
		if(!p->isdir)
    		file_count++;
    }
    
    printTree_Jo(fp, p->next_ptr);
    
    return;

}


//when -H flag is used (to send output to html file) 
void printTree_H(FILE *fp, tnode t) {
	node *p = t;
	int i;
	char *front = "|----", *down = "|&emsp;&emsp;";		// &emsp;  for spacing in html document
	
    if(!p)
        return;
    
    if(p->isrootNode || p->fname[0] != '.') {
		fprintf(fp, "\n");
		for(i = 0; i < count; i++) {    	
				fprintf(fp, "%s", down);
		}
		
		if(count >= 0 && !p->isrootNode) {
			fprintf(fp, "%s", front);
		}
		
		
		if(p->isdir) {
			//printing directory in html document with red colour
			fprintf(fp, "<a href=\"%s\" style=color:red;> %s </a><br>\n", p->info.fpath, p->fname);
			
		}
		else {
			//printing executable file in html document with green colour and other files with blue colour
			if(!access(p->fname,X_OK) || !strcmp(p->fname, "a.out")) {
				
				fprintf(fp, "<a href=\"%s\" style=color:green;> %s </a><br>\n", p->info.fpath, p->fname);
			
			}
			else
				fprintf(fp, "<a href=\"%s\" style=color:blue;> %s </a><br>\n", p->info.fpath, p->fname);
		}
		
		if(p->isdir) {
			if(p->isrootNode)
				printTree_H(fp, p->inner_ptr);
			else {
				dir_count++;
				count++;
				printTree_H(fp, p->inner_ptr);
				count--;
			}
		} 
		if(!p->isdir)
    		file_count++;
    }
    
    printTree_H(fp, p->next_ptr);
    
    return;

}

//when -X flag is used (display output in XML format) 
void printTree_X(tnode t) {
	node *p = t;
	int i;
	char *space = "     ";
    if(!p)
        return;
	   	
    if(p->isrootNode || p->fname[0] != '.') {
		printf("\n");
		for(i = 0; i <= count; i++) {    	
				printf("%s", space);
		}
		
		
		if(p->isdir) 
			printf("<directory name=\"%s\">", p->fname);
		else 
			printf("<file name=\"%s\"></file>", p->fname);
		
		
		if(p->isdir) {
			if(p->isrootNode) {
				count++;
				printTree_X(p->inner_ptr);
				count--;
				printf("\n");
				for(i = 0; i <= count; i++) {    	
					printf("%s", space);
				}
				printf("</directory>\n");
				printf("%s<report>\n", space);
				printf("%s%s<directories>%d</directories>\n", space, space, dir_count);
				printf("%s%s<files>%d</files>\n", space, space, file_count);
				printf("%s</report>\n", space);
				printf("</tree>");
			}
			else {
				dir_count++;
				count++;
				printTree_X(p->inner_ptr);
				printf("\n");
				
				count--;
				for(i = 0; i <= count; i++) {    	
					printf("%s", space);
				}
				printf("</directory>");
			}
		} 
		if(!p->isdir)
    		file_count++;
    }
    
    printTree_X(p->next_ptr);
    
    return;

}

//when -X -o used to send xml output to file 
void printTree_Xo(FILE *fp, tnode t) {
	node *p = t;
	int i;
	char *space = "     ";
    if(!p)
        return;
	   	
    if(p->isrootNode || p->fname[0] != '.') {
		fprintf(fp, "\n");
		for(i = 0; i <= count; i++) {    	
				fprintf(fp, "%s", space);
		}
		
		
		if(p->isdir) 
			fprintf(fp, "<directory name=\"%s\">", p->fname);
		else 
			fprintf(fp, "<file name=\"%s\"></file>", p->fname);
		
		
		if(p->isdir) {
			if(p->isrootNode) {
				count++;
				printTree_Xo(fp, p->inner_ptr);
				count--;
				fprintf(fp, "\n");
				for(i = 0; i <= count; i++) {    	
					fprintf(fp, "%s", space);
				}
				fprintf(fp, "</directory>\n");
				fprintf(fp, "%s<report>\n", space);
				fprintf(fp, "%s%s<directories>%d</directories>\n", space, space, dir_count);
				fprintf(fp, "%s%s<files>%d</files>\n", space, space, file_count);
				fprintf(fp, "%s</report>\n", space);
				fprintf(fp, "</tree>");
			}
			else {
				dir_count++;
				count++;
				printTree_Xo(fp, p->inner_ptr);
				fprintf(fp, "\n");
				
				count--;
				for(i = 0; i <= count; i++) {    	
					fprintf(fp, "%s", space);
				}
				fprintf(fp, "</directory>");
			}
		} 
		if(!p->isdir)
    		file_count++;
    }
    
    printTree_Xo(fp, p->next_ptr);
    
    return;

}
