#declare variable for compiler
CC=gcc

#declare variable for flags
CFLAGS=-c -Wall


#all target will compile all files
all: proj

proj: tree.h createTree.o sortTree.o printTree.o tree.o main.o colours.o pattern.o json_html_xml.o
	$(CC) tree.h createTree.o sortTree.o printTree.o tree.o main.o colours.o pattern.o  json_html_xml.o -o run

main.o: main.c
	$(CC) $(CFLAGS) main.c

tree.o: tree.c
	$(CC) $(CFLAGS) tree.c

colours.o: colours.c
	$(CC) $(CFLAGS) colours.c

createTree.o: createTree.c
	$(CC) $(CFLAGS) createTree.c	

sortTree.o: sortTree.c
	$(CC) $(CFLAGS) sortTree.c
	
printTree.o: printTree.c
	$(CC) $(CFLAGS) printTree.c

pattern.o: pattern.c
	$(CC) $(CFLAGS) pattern.c
	
json_html_xml.o: json_html_xml.c
	$(CC) $(CFLAGS) json_html_xml.c

clean:
	rm -rf *o run
	
	
