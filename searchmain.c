#include "header.h"

int main (int argc, char **argv)
{
  int Sflag = 0;
  int tflag = 0;
  char *svalue = NULL;
  long int srvalue = 0;
  char *fvalue = "\0";
  char *tvalue = NULL;
  int index;
  int c;
  char *trvalue = NULL;

  opterr = 0;

  while ((c = getopt (argc, argv, "Ss:f:t:")) != -1){
    switch (c){
      case 'S':
        Sflag = 1;
        break;
      case 's':
        svalue = optarg;
        srvalue = atoi(svalue);
        break;
      case 'f':
        tflag = 1;
        fvalue = optarg;
        break;
      case 't':
        tvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        return 1;
      default:
        abort ();
    }
  }

  if(tvalue == "f"){
        trvalue = "regular file";
    }else if(tvalue == "d"){
        trvalue = "directory";
    }
  
  if(argc<2){
    readingDir(".", Sflag, srvalue, fvalue, tflag, trvalue);
  }
  else{
      if(optind>=argc){
          readingDir(".", Sflag, srvalue, fvalue, tflag, trvalue);
      }
      else{
        for (index = optind; index < argc; index++){
        readingDir(argv[index], Sflag, srvalue, fvalue, tflag, trvalue);
        }
      }
  }
  return 0;
}