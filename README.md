# Tree-Command-Implementation
This repository contains Linux Tree Command Implementation Project in C. 

> Tree is a recursive directory listing program that produces a depth-indented listing of files.

> With no arguments, it lists the files and sub-directories in the current directory.

> When the command is used along with path, it lists files and sub-directories from the directory whose path is mentioned.

> Upon completion of listing all files and directories found, tree returns the total number of files and directories listed.

> It features various options for output manipulation, from file options, sorting options, to graphics options, and support for output in XML, JSON and HTML formats.


# Flags implemented in the project :

------- Listing options -------<br/>
  -a              All files are listed(private files also).<br/>
  -d              List directories only.<br/>
  -f              Print the full path prefix for each file.<br/>
  -L level        Descend only level directories deep.<br/>
  -P pattern      List only those files that match the wild-card pattern given.<br/>
  -I pattern      Do not list files that match the given wild-card pattern.<br/>
  --noreport      Turn off file/directory count at end of tree listing.<br/>
  -o filename     Output to file instead of stdout.<br/>
  
  ------- File options -------<br/>
  -Q              Quote filenames with double quotes.<br/>
  -p              Print the protections for each file.<br/>
  -u              Displays file owner name.<br/>
  -s              Print the size in bytes of each file.<br/>
  -h              Print the size in a more human readable way.<br/>
  -D              Print the date of last modification.<br/>
  --inodes        Print inode number of each file.<br/>
  
  ------- Sorting options -------<br/>
  -t              Sort files by last modification time.<br/>
  -r              Reverse alphabetical order of files/directories.<br/>
  
  ------- XML/HTML/JSON options -------<br/>
  -X              Prints out an XML representation of the tree.<br/>
  -X -o filename  Output an XML representation of the tree to filename.<br/>
  -J              Prints out an JSON representation of the tree.<br/>
  -J -o filename  Output an JSON representation of the tree to filename.<br/>
  -H -o filename  Output an HTML format of the tree to filename.<br/>

# How to run the project?<br/>
1) First compile all project c files using makefile. (Makefile helps to compile uncompiled files only and avoids repetitive compilations)<br/>
Use this command -> make all<br/>

2) To execute the project,<br/>
Use this command (without arguments) -> ./run <br/>
Use this command (with arguments) -> ./run path flag1 flag2 <br/>
Here you can use path and flags if needed.<br/>

3) To clean .o files (object files) and executable file created after project compilation,<br/>
Use this command -> make clean <br/>

