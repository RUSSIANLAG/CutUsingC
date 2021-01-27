#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "assign2funcs.h"

int main ( int argc, char **argv ) {
        struct _ParamCuts paramC;
        int iReturn;
        char *inbuff;
        int ret;
        char *p;
        FILE *fptr = fopen("input", "r");
          
        iReturn = commandLineCheck(argc,argv,&paramC); //Checks for errors
        if (iReturn==0){                                         //Starts the main loop if there are no errors  
                int count = paramC.fieldCount;
                char str1[2] = {paramC.inputDelim , '\0'};
                char delimIn[1] = "";
                strcpy(delimIn,str1);

        if (fptr == NULL)                                       //Checks if the file is provided
        {
                printf ("Error opening the file\n\n'");
                exit(1); 
        } else {
                inbuff = malloc(sizeof(char) * 4096);           //allocates buffer memory
                while(!feof(fptr)){                             //Loops until the end of the file is reached
                        memset(inbuff, 0, 4096);
                        ret = fscanf(fptr, "%4095[^\n]\n",inbuff);      //Scans the line currently being fed
                        if (ret != EOF) {                               //Checks if the line is valid
                                int i=0;
                                char *array[256];
                                int a;
                                p = strtok (inbuff, delimIn);           //Pointer uses input delimiter
                                while (p != NULL) {                     //Loops to fill array with seperated strings
                                        array[i++] = p;                 //Iterates
                                        p = strtok (NULL, delimIn);     //Nulls the in put delim
                                          }
                                        for (i = 0; i < count; ++i){            //Loops through the fields seperated by delims
                                                a = paramC.fieldNums[i]-1;
                                                 if (i<count-1){
                                                        printf("%s%c", array[a], paramC.outputDelim); //Prints the string and outputdelim
                                                        }
                                                else  {
                                                        printf("%s", array[a]);                         //If its the final string, prints only the string
                                                }
                                         }
                         printf("\n");
                                }
                        }
                }
        }
free(inbuff);   //free the buffer
fclose(fptr);   //close the file 
return(iReturn);
}
