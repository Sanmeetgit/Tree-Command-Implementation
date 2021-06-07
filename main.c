
#include "tree.h"

int main(int argc, char *argv[]) {
    
    //using switch case and passing argc (number of command line arguments)
    switch(argc) {
    	case 1:
    		tree_arg1(".");
    		break;
    	case 2:
    		if(!strcmp(argv[1], "--help"))
    			help("menu");
    		else if(!strcmp(argv[1], "-a") || !strcmp(argv[1], "-d") || !strcmp(argv[1], "-s") || !strcmp(argv[1], "-f") || !strcmp(argv[1], "-Q") || !strcmp(argv[1], "--noreport") || !strcmp(argv[1], "--inodes") || !strcmp(argv[1], "-h") || !strcmp(argv[1], "-p") || !strcmp(argv[1], "-D") || !strcmp(argv[1], "-u") || !strcmp(argv[1], "-r") || !strcmp(argv[1], "-t") || !strcmp(argv[1], "-J") || !strcmp(argv[1], "-X") || !strcmp(argv[1], "-all"))
    			tree_arg2(".", argv[1]);
    		else
    			tree_arg1(argv[1]);
    		break;
    	case 3:
    		if(!strcmp(argv[1], "-L") || !strcmp(argv[1], "-o") || !strcmp(argv[1], "-P") || !strcmp(argv[1], "-I")) 
    			tree_arg3(".", argv[1], argv[2]);
    		else
    			tree_arg2(argv[1], argv[2]);
    		break;
    	case 4:
    		if(!strcmp(argv[1], "-H"))
    			tree_arg4(".", argv[1], argv[2], argv[3]);
    		else if(!strcmp(argv[1], "-J"))
    			tree_arg4(".", argv[1], argv[2], argv[3]);
    		else if(!strcmp(argv[1], "-X"))
    			tree_arg4(".", argv[1], argv[2], argv[3]);
    		else 
    			tree_arg3(argv[1], argv[2], argv[3]);
    		break;
    	case 5:
    		tree_arg4(argv[1], argv[2], argv[3], argv[4]);
    		break;
    	default:
    		printf("Enter valid command\n");
    		break;
    }
    return 0;
}

