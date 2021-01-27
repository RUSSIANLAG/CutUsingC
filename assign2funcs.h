typedef struct _ParamCuts {
        char inputDelim;
        char outputDelim;
        int *fieldNums;
        int fieldCount;
} * ParamCuts;

int commandLineCheck(int argc, char ** argv, ParamCuts paramC);
