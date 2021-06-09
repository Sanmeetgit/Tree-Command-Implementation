# Tree-Command-Implementation
This repository contains Linux Tree Command Implementation Project in C. 

> Tree is a recursive directory listing program that produces a depth-indented listing of files.

> With no arguments, it lists the files and sub-directories in the current directory.

> When the command is used along with path, it lists files and sub-directories from the directory whose path is mentioned.

> Upon completion of listing all files and directories found, tree returns the total number of files and directories listed.

> It features various options for output manipulation, from file options, sorting options, to graphics options, and support for output in XML, JSON and HTML formats.


# Flags implemented in the project :

------- Listing options -------
  -a              All files are listed(private files also).
  -d              List directories only.
  -f              Print the full path prefix for each file.
  -L level        Descend only level directories deep.
  -P pattern      List only those files that match the wild-card pattern given.
  -I pattern      Do not list files that match the given wild-card pattern.
  --noreport      Turn off file/directory count at end of tree listing.
  -o filename     Output to file instead of stdout.
  
  ------- File options -------
  -Q              Quote filenames with double quotes.
  -p              Print the protections for each file.
  -u              Displays file owner name.
  -s              Print the size in bytes of each file.
  -h              Print the size in a more human readable way.
  -D              Print the date of last modification.
  --inodes        Print inode number of each file.
  
  ------- Sorting options -------
  -t              Sort files by last modification time.
  -r              Reverse alphabetical order of files/directories.
  
  ------- XML/HTML/JSON options -------
  -X              Prints out an XML representation of the tree.
  -X -o filename  Output an XML representation of the tree to filename.	
  -J              Prints out an JSON representation of the tree.
  -J -o filename  Output an JSON representation of the tree to filename.
  -H -o filename  Output an HTML format of the tree to filename.

# How to run the project?
1) First compile all project c files using makefile. (Makefile helps to compile uncompiled files only and avoids repetitive compilations)
Use this command -> make all

2) To execute the project,
Use this command (without arguments) -> ./run
Use this command (with arguments) -> ./run path flag1 flag2
Here you can use path and flags if needed.

3) To clean .o files (object files) and executable file created after project compilation,
Use this command -> make clean

