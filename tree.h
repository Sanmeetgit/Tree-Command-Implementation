#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<pwd.h>
#include<time.h>

#define LENGTH_OF_LONG_INT 10

int count;
int file_count;
int dir_count;

//struct ADT 
typedef struct node {
    char *fname;
    int isdir;
    int isrootNode;
    
    struct information {
    	unsigned long int fsize;
    	char* fpath;
    	char* fpermissions;
    	char* fuser_name;
    	struct last_modification {
    		short fdate;
    		short fmon;
    		short fyear;
    		short fhour;
    		short fmin;
    		short fsec;
    	}last_mod;
    	long int inode;
    }info;
    
    struct node *next_ptr;
    struct node *inner_ptr;
}node;


typedef node* tnode;

//creating tree functions
node* createTreeNode(char *name);
node* createTree_1(char *rootname);
node* createTree(char *rootname);

node* createPatternTree(char *rootname, char *pattern, char *flag);
node* createPatternTree_1(char *rootname, char *pattern, char *flag);

//sorting functions 
node* midNode(tnode p);

tnode sort_alpha(tnode pt);
tnode MergeTwoSLL_alpha(tnode L1, tnode L2);
tnode mergeSort_alpha(tnode head);

tnode sort_rev_alpha(tnode pt);
tnode MergeTwoSLL_rev_alpha(tnode L1, tnode L2);
tnode mergeSort_rev_alpha(tnode head);

tnode MergeTwoSLL_last_mod(tnode L1, tnode L2);
tnode mergeSort_last_mod(tnode head);
tnode sort_last_mod(tnode pt);
int last_mod_compare(tnode n1, tnode n2);


//file details related functions
unsigned long int get_Size(char *file_name);
long int get_fileSize(char *file_path);
long int get_inode(char *file_name);
char* get_permissions(char *file_name);
void get_last_mod(node *ptr, char *file_name);
char* get_username(char* file_name);

//functions to check whether wild-card pattern is matched or not
int match_pattern(char *str, char *patt);


//printing tree functions for various flags
void printTree(tnode t);
void printTree_a(tnode t);
void printTree_d(tnode t);
void printTree_s(tnode t);
void printTree_f(tnode t);
void printTree_Q(tnode t);
void printTree_L(tnode t, int level);
void printTree_ino(tnode t);
void printTree_h(tnode t);
void printTree_p(tnode t);
void printTree_D(tnode t);
void printTree_u(tnode t);
void printTree_o(FILE *fp, tnode t);
void printTree_all(tnode t);

void printTree_J(tnode t);
void printTree_Jo(FILE *fp, tnode t);
void printTree_H(FILE *fp, tnode t);
void printTree_X(tnode t);
void printTree_Xo(FILE *fp, tnode t);


//declarations for different ANSI colours
void black();
void red();
void green();
void yellow();

void blue();
void purple();
void cyan();
void white();

void reset();

//function for --help flag
void help(char *file_name);

//functions according to number command line arguments
void tree_arg1(char *rootname);
void tree_arg2(char *rootname, char *flag);
void tree_arg3(char *rootname, char *arg1, char *arg2);
void tree_arg4(char *rootname, char *arg1, char *arg2, char *arg3);

