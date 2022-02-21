/* primary_header.h */
#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

void readingDir(char * kar, int Sflag, long int srvalue, char *fvalue,int tflag, char *trvalue);

#endif