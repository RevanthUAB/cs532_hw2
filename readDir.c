#include "header.h"

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

size_t getFileSize(const char* filename){
	struct stat st;
	if(stat(filename, &st) != 0){
		return 0;
	}
	return st.st_size;
}

void readingDir(char * kar, int Sflag, long int srvalue, char *fvalue,int tflag, char *trvalue){
	struct dirent *dirent;
	DIR *parentDir;

	parentDir = opendir(kar);
	if(parentDir == NULL){
		printf("Error opening directory '%s'\n", kar);
		exit(-1);
	}
    
	int count = 1;
	while((dirent = readdir(parentDir)) != NULL){
        if(strstr(dirent->d_name,fvalue)){
            if(strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") !=0 && (getFileSize(dirent->d_name)>=srvalue)){
                if(tflag==1 && filetype(dirent->d_type)==trvalue){
					printf("[%d] %s (%s)", count, dirent->d_name, filetype(dirent->d_type));
				}else{
					printf("[%d] %s (%s)", count, dirent->d_name, filetype(dirent->d_type));
				}
                if(Sflag==1){
                    printf("\t[%ld]\n", getFileSize(dirent->d_name));
                }else{printf("\n");}
                count++;
                if(dirent->d_type == DT_DIR){
                    char * childDir =(char *)malloc(sizeof(dirent->d_name) * sizeof(char));
                    strcpy(childDir, kar);
                    strcat(childDir, "/");		
                    strcat(childDir,dirent->d_name);
                    readingDir(childDir,Sflag,srvalue,fvalue,tflag,trvalue);
                    free(childDir);
                }	
            }
        }
	}
	closedir(parentDir);
}