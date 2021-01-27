#include "assign2funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 103
int commandLineCheck(int argc, char ** argv, ParamCuts paramC)
{
int exitProg=0;
        if ((argc<3) || (argc>MAX) )
           {
            exitProg=1;
            paramC->fieldCount=0;
            paramC->fieldNums=NULL;
            fprintf(stderr,"%s Wrong # of command line args \n", argv[0]);
        }
        else
           {
           if ((strlen(argv[1])!=1) || (strlen(argv[2])!=1 ))
            {
                exitProg=1;
                fprintf(stderr,"%s invalid delimiters \n", argv[0]);
                    }
                    paramC->inputDelim = argv[1][0];
                    paramC->outputDelim = argv[2][0];
                   int mainfieldNum=0;
                   int N=paramC->fieldCount = argc-3;
                   paramC->fieldNums = (int *) malloc(N*sizeof(int));
                   for (int j=0; j<N; j++)
                   {
                      int fieldNumNow = atoi(argv[j+3]);
                      if (fieldNumNow<=mainfieldNum)
                      {
                         exitProg=1;
                                 fprintf(stderr,"%s field # out of sequence\n", argv[0]);
                                 free(paramC->fieldNums);
                             break;
                          }
                          paramC->fieldNums[j]=fieldNumNow;
                          mainfieldNum = fieldNumNow;
                   }
           }
        return(exitProg);
}
