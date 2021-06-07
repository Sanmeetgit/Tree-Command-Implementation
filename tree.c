#include "tree.h"

//when 1 command line argument is used
void tree_arg1(char *rootname) {
	tnode p = NULL;
	
	//creating tree structure and sorting alphabetically
	p = createTree(rootname);
	if(p) 
		p->inner_ptr = sort_alpha(p->inner_ptr);
	printTree(p);
	printf("\n");
    	
    printf("\n%d directories, %d files\n", dir_count, file_count);
	
}

//when 2 command line arguments are used
void tree_arg2(char *rootname, char *flag) {
	
	//creating tree structure and sorting alphabetically
	tnode p = createTree(rootname);
	if(p) 
		p->inner_ptr = sort_alpha(p->inner_ptr);
	
	//comparing command line argument with different flags
	if(!strcmp(flag, "-a")) {
		printTree_a(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-d")) {
		printTree_d(p);
		printf("\n");
    	
    	printf("\n%d directories\n", dir_count);
	}
	else if(!strcmp(flag, "-s")) {
		printTree_s(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-f")) {
		printTree_f(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-Q")) {
		printTree_Q(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "--noreport")) {
		printTree(p);
		printf("\n");
	}
	else if(!strcmp(flag, "--inodes")) {
		printTree_ino(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-h")) {
		printTree_h(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-p")) {
		printTree_p(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-D")) {
		printTree_D(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-all")) {
		printTree_all(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-u")) {
		printTree_u(p);
		printf("\n");
    	
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-r")) {
		if(p) {
			//sorting tree structure in reverse alphabetical order
			p->inner_ptr = sort_rev_alpha(p->inner_ptr);
			printTree(p);
    	}
    	printf("\n");
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-t")) {
		if(p) {
			//sorting tree structure according to last modification time
			p->inner_ptr = sort_last_mod(p->inner_ptr);
			printTree(p);
    	}
    	printf("\n");
    	printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	
	else if(!strcmp(flag, "-J")) {
		if(p) {
			printTree_J(p);
			//printf("\n");
		}
		else {
			printf("\n");
			printf("[\n");
			printf("     {\"type\":\"unknown\",\"name\":\"%s\",\"contents\":[{\"error\": \"opening dir\"}\n     ]},\n", rootname);
	    		printf("     {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n]\n", dir_count, file_count);
    		}
    		//printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else if(!strcmp(flag, "-X")) {
		if(p) {
			//p->inner_ptr = sort_alpha(p->inner_ptr);
			printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			printf("<tree>");
			printTree_X(p);
			printf("\n");
		}
		else {
			printf("\n");
			printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			printf("<tree>\n");
			printf("     <unknown name=\"%s\"><error>opening dir</error>\n     </unknown>\n", rootname);
			printf("     <report>\n          <directories>%d</directories>\n          <files>%d</files>\n     </report>\n", dir_count, file_count);
			printf("</tree>\n");
    	}
    		//printf("\n%d directories, %d files\n", dir_count, file_count);
	}
	else {
		printf("\nEnter valid flag\n");
	}

}

void tree_arg3(char *rootname, char *arg1, char *arg2) {
	if(!strcmp(arg1, "-L")) {
		tnode p = createTree(rootname);
		if(p) 
			p->inner_ptr = sort_alpha(p->inner_ptr);
		
		//checking level exceeded or not
		if(atoi(arg2) > 0) {
			printTree_L(p, atoi(arg2));
			printf("\n");
			
			printf("\n%d directories, %d files\n", dir_count, file_count);
		}
		else {
			printf("Level must be greater than 0\n");
		}
	}
	else if(!strcmp(arg1, "-o")) {
		tnode p = createTree(rootname);
		if(p) 
			p->inner_ptr = sort_alpha(p->inner_ptr);
		FILE *fp;
		fp = fopen(arg2, "w+");
		printTree_o(fp, p);
		
		fprintf(fp, "\n");
    	
    		fprintf(fp, "\n%d directories, %d files\n", dir_count, file_count);
    		fclose(fp);
	}
	else if(!strcmp(arg1, "-P") || !strcmp(arg1, "-I")) {
		tnode p = createPatternTree(rootname, arg2, arg1);
		if(p) {
			p->inner_ptr = sort_alpha(p->inner_ptr);
			printTree(p);
		}
		printf("\n");
			
		printf("\n%d directories, %d files\n", dir_count, file_count);
	}

}

void tree_arg4(char *rootname, char *arg1, char *arg2, char *arg3) {
	tnode p = createTree(rootname);
	if(p) 
		p->inner_ptr = sort_alpha(p->inner_ptr);
	
	char host[256];
	if(!strcmp(arg1, "-H") && !strcmp(arg2, "-o")) {
		if(!p) {
			printf("\n");
			return;
		}
		//p->inner_ptr = sort_alpha(p->inner_ptr);
		FILE *fp;
		fp = fopen(arg3, "w+");
		fprintf(fp, "<!DOCTYPE html>\n");
		fprintf(fp, "<html>\n<head>\n");
		fprintf(fp, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n<meta name=\"Author\" content=\"Made by \'tree\'\">\n");
		fprintf(fp, "<title>Tree Command</title>\n");
		fprintf(fp, "<style>\n");
		fprintf(fp, "body {\nfont-family : ariel, \nmonospace, sans-serif;\n}");
		fprintf(fp, "A:hover   { color : #000000; font-weight : normal; text-decoration : underline; background-color : yellow; margin : 0px 0px 0px 0px; padding : 0px 0px 0px 0px; display: inline; }");
		fprintf(fp, "A:link    { font-weight : normal; text-decoration : none; margin : 0px 0px 0px 0px; padding : 0px 0px 0px 0px; display: inline; }");
		fprintf(fp, "</style>\n");
		fprintf(fp, "</head>\n<body>\n");
		fprintf(fp, "<h1>Directory Tree</h1>\n");
		
 		gethostname(host, sizeof(host));
 		fprintf(fp, "<a href=\"link.html\" style=color:purple;> %s </a><br>\n", host);
		printTree_H(fp, p);
		fprintf(fp, "<br><br><br>\n");
		fprintf(fp, "directories  %d, files %d<br>\n", dir_count, file_count);
		fprintf(fp, "<br><br><hr><br>\n");
		fprintf(fp, "<p class=\"VERSION\"; style=\"color:black;font:ariel;font-size:13px;\">Tree command implementation by<br>Sanmeet Wakchaure<br>MIS - 111903087<br>SY comp, div 2<br>\n");
		fprintf(fp, "</body>\n</html>\n");
		fclose(fp);
	}
	else if(!strcmp(arg1, "-J") && !strcmp(arg2, "-o")) {
		FILE *fp = fopen(arg3, "w+");
		if(p) {
			printTree_Jo(fp, p);
		}
		else {
			printf("\n");
			fprintf(fp, "[\n");
			fprintf(fp, "     {\"type\":\"unknown\",\"name\":\"%s\",\"contents\":[{\"error\": \"opening dir\"}\n     ]},\n", rootname);
	    	fprintf(fp, "     {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n]\n", dir_count, file_count);
		}
		fclose(fp);
	}
	else if(!strcmp(arg1, "-X") && !strcmp(arg2, "-o")) {
		FILE *fp = fopen(arg3, "w+");
		if(p) {
			fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			fprintf(fp, "<tree>");
			printTree_Xo(fp, p);
		}
		else {
			printf("\n");
			fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			fprintf(fp, "<tree>\n");
			fprintf(fp, "     <unknown name=\"%s\"><error>opening dir</error>\n     </unknown>\n", rootname);
			fprintf(fp, "     <report>\n          <directories>%d</directories>\n          <files>%d</files>\n     </report>\n", dir_count, file_count);
			fprintf(fp, "</tree>\n");
		}
		fclose(fp);
	}
}
