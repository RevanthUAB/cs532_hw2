# Home Work 2 - Files and Directories hierarchical search

### Description

The goal of this project is to implement a C program that will take the arguments provided in the command line to excute the functions or methods that are asked to create such as displaying the size, checking the strings, checking for directories or regular files and finally comparing the size of the file and display them which are higher than required.

Read keywords, command-line arguments, search files, search directories, c language.

### Prerequisites

Requirements for the software and other tools to build, test and push
- [Example 1]GCC compiler
- [Example 2]C language

## Running the tests

To compile the file 
    
    $make

And to run the output file, these are several ways to Run the command lines as required nad can be changed according to need,

    $./a.out
    $./a.out ../programs
    $./a.out /path/
    $./a.out -S ../programs
    $./a.out -s 1024
    $./a.out -s 1024 ../programs 
    $./a.out -f jpg
    $./a.out -f jpg -s 1024
    $./a.out -s 1024 -f jpg
    $./a.out -S -s 1024 -f jpg
 
Press Enter and will display the results required.

### Sample Tests

So when you run the program with 
 ./a.out -S // Displays the current folder along with the with their sizes in bytes.

    [1] .vscode (directory) [512]
    [1] c_cpp_properties.json (regular file)        [0]
    [2] a.out (regular file)        [24576]
    [3] delete.c (regular file)     [1095]
    [4] header.h (regular file)     [322]
    [5] makefile (regular file)     [415]
    [6] nari (directory)    [512]
    [1] makefile (regular file)     [415]
    [7] readDir.c (regular file)    [2067]
    [8] readDir.o (regular file)    [12696]
    [9] README.md (regular file)    [2202]
    [10] searchmain.c (regular file)        [1497]
    [11] searchmain.o (regular file)        [9456]
    [12] text.txt (regular file)    [155]

## Authors

  - **Revanth Kari** - *CS 532* -
   [GitHub](https://github.com/RevanthUAB/cs532_hw2)

## Acknowledgments

  - To create the arguments the usage of getopt method is used from GNU getopt and the makefile and header file is created using the file given in the lab files provided 

[//]: #
  [techoverflow]:<https://techoverflow.net/2013/08/21/how-to-get-filesize-using-stat-in-cc/>
  [GNU]:<https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html>
  [google]:<every string ends with /0 in c>
  [geeksforgeeks]:<https://www.geeksforgeeks.org/unsigned-char-in-c-with-examples/>
  [Assistedcoding]:<http://solver.assistedcoding.eu/makefilegen>
  [codeforwin]:<https://codeforwin.org/2018/03/c-program-to-list-all-files-in-a-directory-recursively.html>
  [stackoverflow]:<https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c>