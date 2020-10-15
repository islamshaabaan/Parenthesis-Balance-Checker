/**
 * @file search.c
 * @author Islam Frahat (islam.mostafa.f@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "read.h"

void readfile1(char* file_name)
{	
    char const* const fileName = file_name; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char line[256];
    char wholefile[256];
    int count=0;	
    while (fgets(line, sizeof(line), file)) {
	count++;
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%d %s", count,line); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);
  	
	
}
char *readfile2(char* file_name)
{
    char const* const fileName = file_name; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char *code;
    
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    code = malloc(f_size);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char)c;
    
    }


    // don't forget to terminate with the null character
    code[n] = '\0';        
    
    return code;
}