#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>

char *filetype(unsigned char type) {
	char *str;
  	switch(type) {
  	case DT_BLK: str = "block device"; break;
  	case DT_CHR: str = "character device"; break;
  	case DT_DIR: str = "directory"; break;
  	case DT_FIFO: str = "named pipe (FIFO)"; break;
  	case DT_LNK: str = "symbolic link"; break;
  	case DT_REG: str = "regular file"; break;
  	case DT_SOCK: str = "UNIX domain socket"; break;
  	case DT_UNKNOWN: str = "unknown file type"; break;
  	default: str = "UNKNOWN";
	}
  	return str;
}

size_t getFileSize(const char* filename, char *file){
	struct stat st;
    char *path = (char *)malloc(10000 * sizeof(char));
    strcpy(path, file);
    strcat(path, "/");
    strcat(path, filename);
	if(stat(path, &st) == -1){
		perror("stat");
        printf("%s",path);
        exit(EXIT_FAILURE);
	}
	return st.st_size;
}

void readingDir(char *kar, int Sflag, long int srvalue, char *fvalue, int tflag, char *trvalue){
    struct dirent *dirent;
    DIR *parentDir;
    
    size_t (*getFileSize_ptr)(const char*, char*) = &getFileSize;

    parentDir = opendir(kar);
    if(parentDir == NULL){
        printf("Error opening directory == '%s'\n",kar);
        exit(-1);
    }

    int count = 1;
    while((dirent = readdir(parentDir)) != NULL){
        if(strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") !=0){
            if (((*getFileSize_ptr)(dirent->d_name, kar) >= srvalue) || (strcmp(filetype(dirent->d_type),"directory") == 0))
            {
                if (tflag == 1)
                {
                    if(filetype(dirent->d_type)==trvalue)
                    {
                        if(strstr(dirent->d_name, fvalue))
                        {
                            printf("[%d] %s (%s)", count, dirent->d_name, filetype(dirent->d_type));
                        }
                        if(Sflag==1)
                        {
                            if(strstr(dirent->d_name, fvalue))
                            {
                            printf("\t[%lu]\n", (*getFileSize_ptr)(dirent->d_name, kar));
                            }
                        }
                        else
                        {
                            if(strstr(dirent->d_name, fvalue))
                            {
                            printf("\n");
                            }
                        }
                    }
                }
                else
                {
                    if(strstr(dirent->d_name, fvalue))
                    {
                        printf("[%d] %s (%s)", count, dirent->d_name, filetype(dirent->d_type));
                    }
                    if(Sflag==1)
                    {
                        if(strstr(dirent->d_name, fvalue))
                        {
                            printf("\t[%lu]\n", (*getFileSize_ptr)(dirent->d_name, kar));
                        }
                    }
                    else
                    {
                        if(strstr(dirent->d_name, fvalue))
                        {
                            printf("\n");
                        }
                    }
                }            
                count++;
                if(dirent->d_type == DT_DIR){
                char * childDir = (char *)malloc(10000 * sizeof(char));
                strcpy(childDir, kar);
                strcat(childDir, "/");
                strcat(childDir, dirent->d_name);
                readingDir(childDir,Sflag,srvalue,fvalue,tflag,trvalue);
                free(childDir);
                }
            }
        }
    }
    closedir(parentDir);
}

int main(int argc, char **argv){
    
    int Sflag = 0;
    int tflag = 0;
    int fflag = 0;
    char *svalue = NULL;
    long int srvalue = 0;
    char *fvalue = "\0";
    char *tvalue = NULL;
    int index;
    int c;
    char *trvalue = NULL;

    opterr = 0;

    while ((c = getopt(argc, argv, "Ss:f:t:")) != -1){
        switch (c)
        {
        case 'S':
            Sflag = 1;
            break;
        case 's':
            svalue = optarg;
            srvalue = atoi(svalue);
            break;
        case 'f':
            fflag = 1;
            fvalue = optarg;
            break;
        case 't':
            tflag = 1;
            tvalue = optarg;
            break;
        case '?':
            if (optopt == 'c')
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            }
            else if (isprint (optopt))
            {
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            }
            else
            {
                fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
            }
            return 1;
        default:
            abort();
        }
    }  
    
    if (tflag==1)
    {
        if (strcmp(tvalue,"f") == 0)
        {
            trvalue = "regular file";
        }
        else if (strcmp(tvalue,"d") == 0)
        {
            trvalue = "directory";
        }
        else
        {
            printf("Please give the value for t flag either f or d");
            exit(-1);
        }
    }
    
    void (*readingDir_ptr)(char*, int, long int, char*, int, char*) = &readingDir;

    if (argc<2)
    {
        (*readingDir_ptr)(".", Sflag, srvalue, fvalue, tflag, trvalue);
    }
    else
    {
        if (optind>=argc)
        {
            (*readingDir_ptr)(".", Sflag, srvalue, fvalue, tflag, trvalue);
        }
        else
        {
            for (index = optind; index < argc; index++)
            {
                (*readingDir_ptr)(argv[index], Sflag, srvalue, fvalue, tflag, trvalue);
            }
            
        }
        
    }
    return 0;
}