# Tree-Command-Implementation
This repository contains Linux Tree Command Implementation Project in C. 

> Tree is a recursive directory listing program that produces a depth-indented listing of files.<br/>

> With no arguments, it lists the files and sub-directories in the current directory.<br/>

> When the command is used along with path, it lists files and sub-directories from the directory whose path is mentioned.<br/>

> Upon completion of listing all files and directories found, tree returns the total number of files and directories listed.<br/>

> It features various options for output manipulation, from file options, sorting options, to graphics options, and support for output in XML, JSON and HTML formats.<br/>


# Flags implemented in the project :

------- Listing options -------<br/>
  <table> 
  <tr>
    <td>-a</td>
    <td>All files are listed(private files also).</td>
  </tr>
  <tr>
    <td>-d</td>
    <td>List directories only.</td>
  </tr>
  <tr>
    <td>-f</td>
    <td>Print the full path prefix for each file.</td>
  </tr>
  <tr>
    <td>-L level</td>
    <td>Descend only level directories deep.</td>
  </tr>
  <tr>
    <td>-P pattern</td>
    <td>List only those files that match the wild-card pattern given.</td>
  </tr>
  <tr>
    <td>-I pattern</td>
    <td>Do not list files that match the given wild-card pattern.</td>
  </tr>
  <tr>
    <td>--noreport</td>
    <td>Turn off file/directory count at end of tree listing.</td>
  </tr>
  <tr>
    <td>-o filename</td>
    <td>Output to file instead of stdout.</td>
  </tr>
</table>
  -a &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;           All files are listed(private files also).<br/>
  -d &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;             List directories only.<br/>
  -f &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;          Print the full path prefix for each file.<br/>
  -L level &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       Descend only level directories deep.<br/>
  -P pattern &nbsp; &nbsp; &nbsp; &nbsp;       List only those files that match the wild-card pattern given.<br/>
  -I pattern &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;      Do not list files that match the given wild-card pattern.<br/>
  --noreport &nbsp; &nbsp; &nbsp; &nbsp;       Turn off file/directory count at end of tree listing.<br/>
  -o filename &nbsp; &nbsp; &nbsp;    Output to file instead of stdout.<br/>
  
  ------- File options -------<br/>
  -Q &nbsp; &nbsp; &nbsp;             Quote filenames with double quotes.<br/>
  -p &nbsp; &nbsp; &nbsp;             Print the protections for each file.<br/>
  -u &nbsp; &nbsp; &nbsp;             Displays file owner name.<br/>
  -s &nbsp; &nbsp; &nbsp;             Print the size in bytes of each file.<br/>
  -h &nbsp; &nbsp; &nbsp;             Print the size in a more human readable way.<br/>
  -D &nbsp; &nbsp; &nbsp;             Print the date of last modification.<br/>
  --inodes &nbsp; &nbsp; &nbsp;       Print inode number of each file.<br/>
  
  ------- Sorting options -------<br/>
  -t &nbsp; &nbsp; &nbsp;             Sort files by last modification time.<br/>
  -r &nbsp; &nbsp; &nbsp;             Reverse alphabetical order of files/directories.<br/>
  
  ------- XML/HTML/JSON options -------<br/>
  -X &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;           Prints out an XML representation of the tree.<br/>
  -X -o filename &nbsp; &nbsp; &nbsp; Output an XML representation of the tree to filename.<br/>
  -J &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;          Prints out an JSON representation of the tree.<br/>
  -J -o filename &nbsp; &nbsp; &nbsp; Output an JSON representation of the tree to filename.<br/>
  -H -o filename &nbsp; &nbsp; &nbsp; Output an HTML format of the tree to filename.<br/>
  
  ------- Miscellaneous options -------<br/>
  --help &nbsp; &nbsp; &nbsp;         Print usage and this help message and exit.<br/>
  --all	&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;	  Print all information about files.<br/>

# How to run the project?<br/>
1) First compile all project c files using makefile. (Makefile helps to compile uncompiled files only and avoids repetitive compilations)<br/>
Use this command -> make all<br/>

2) To execute the project,<br/>
Use this command (without arguments) -> ./run <br/>
Use this command (with arguments) -> ./run path flag1 flag2 <br/>
Here you can use path and flags if needed.<br/>

3) To clean .o files (object files) and executable file created after project compilation,<br/>
Use this command -> make clean <br/>

