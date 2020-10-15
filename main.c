/**
 * @file main.c
 * @author Islam Shaaban(eslam_eslam4140@yahoo.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include "read.h"
#include "stack.h"
#include "balancecheck.h"
#include "newSleep.h"
/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
    
    /*readfile1(argv[1]);*/
    char *code;
    code = readfile2(argv[1]);
    
 
    
    if(areParanthesisBalanced(code))
	printf("All Good");
    else
	printf("txt is not balanced");
  
  return 0;
}
