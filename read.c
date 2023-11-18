#include <stdio.h>

// print error message in red color
#define KRED "\033[0;31m"

/** function that reads and writes a file content onto standard output **/
int read(char *filename ){

    // open the file supplied as argument in read mode
    FILE *fp = fopen(filename, "r");

    // read all characters one at a time and display it to std output
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    // close the file
    fclose(fp);
}

/** function to perform basic validatons on user input for command **/
int validate(int argc, char **args){

    // check if a single filename is provided in argument or not
    if(argc > 2){

        printf("%sError%s: incorrect no. of arguments provided!\n", KRED, KRED);
        return 1;
    }

    // check if file name is provided in argument or not
    if(args[1] == NULL){

        printf("%sError%s: provide a filename to read!\n", KRED, KRED);
        return 1;
    }

    // check if file is present in the current directory or not
    char *filename = args[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){

        printf("%sError:%s no such file '%s' in the directory !!\n", KRED, KRED, filename);
        return 1;
    }

    return 0;
}

int main(int argc, char **args){
	
    /*
        Here,

        argc   : no of arguments count supplied to program
        **args : array of pointers, first index contains C file name and second is file to be read

	    printf("Arg 1 : %s\n", arg[0]);
	    printf("Arg 2 : %s\n", arg[1]);
    */

    int invalid = validate(argc, args);
    return (invalid == 0) ? read(args[1]) : 1;
}
