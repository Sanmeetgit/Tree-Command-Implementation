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
  
  ------- File options -------<br/>
  <table>
    <tr>
      <td>-Q</td>
      <td>Quote filenames with double quotes.</td>
    </tr>
    <tr>
      <td>-p</td>
      <td>Print the protections for each file.</td>
    </tr>
    <tr>
      <td>-u</td>
      <td>Displays file owner name.</td>
    </tr>
    <tr>
      <td>-s</td>
      <td>Print the size in bytes of each file.</td>
    </tr>
    <tr>
      <td>-h</td>
      <td>Print the size in a more human readable way.</td>
    </tr>
    <tr>
      <td>-D</td>
      <td>Print the date of last modification.</td>
    </tr>
    <tr>
      <td>--inodes</td>
      <td>Print inode number of each file.</td>
    </tr>
  </table>
  
  ------- Sorting options -------<br/>
  <table>
    <tr>
      <td>-t</td>
      <td>Sort files by last modification time.</td>
    </tr>
    <tr>
      <td>-r</td>
      <td>Reverse alphabetical order of files/directories.</td>
    </tr>
  </table>
  -t &nbsp; &nbsp; &nbsp;             Sort files by last modification time.<br/>
  -r &nbsp; &nbsp; &nbsp;             Reverse alphabetical order of files/directories.<br/>
  
  ------- XML/HTML/JSON options -------<br/>
  <table>
    <tr>
      <td>-X</td>
      <td>Prints out an XML representation of the tree.</td>
    </tr>
    <tr>
      <td>-X -o filename</td>
      <td>Output an XML representation of the tree to filename.</td>
    </tr>
      <tr>
      <td>-J</td>
      <td>Prints out an JSON representation of the tree.</td>
    </tr>
    <tr>
      <td>-J -o filename</td>
      <td>Output an JSON representation of the tree to filename.</td>
    </tr>
    <tr>
      <td>-H -o filename</td>
      <td>Output an HTML format of the tree to filename.</td>
    </tr>
  </table>
  -X &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;           Prints out an XML representation of the tree.<br/>
  -X -o filename &nbsp; &nbsp; &nbsp; Output an XML representation of the tree to filename.<br/>
  -J &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;          Prints out an JSON representation of the tree.<br/>
  -J -o filename &nbsp; &nbsp; &nbsp; Output an JSON representation of the tree to filename.<br/>
  -H -o filename &nbsp; &nbsp; &nbsp; Output an HTML format of the tree to filename.<br/>
  
  ------- Miscellaneous options -------<br/>
  <table>
    <tr>
      <td>--help</td>
      <td>Print usage and this help message and exit.</td>
    </tr>
    <tr>
      <td>--all</td>
      <td>Print all information about files.</td>
    </tr>
  </table>
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

