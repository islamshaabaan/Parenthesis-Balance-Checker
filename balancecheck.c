
#include <stdbool.h>
#include "stack.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

#define ANSI_COLOR_RESET   "\x1b[0m"

bool isMatchingPair(char character1, char character2) 
{
    
    if (character1 == '(' && character2 == ')') 
        return 1; 
    else if (character1 == '{' && character2 == '}') 
        return 1; 
    else if (character1 == '[' && character2 == ']') 
        return 1; 
    else if (character1 == '<' && character2 == '>')
	return 1;
    else
        return 0; 
} 


bool areParanthesisBalanced(char *txt)
{

    create();
    int i = 0;
    int len = 0;
    /* Traverse the given expression to check matching parenthesis */
    while (txt[i] != '\0') {
         
        /*If the txt[i] is a starting parenthesis then push it*/
        if (txt[i] == '{' || txt[i] == '(' || txt[i] == '[' || txt[i] == '<') 
        {   
	    if(txt[i]== '{')
	    	printf(ANSI_COLOR_RED "%c", txt[i]);
	    else if(txt[i]== '(')
		printf(ANSI_COLOR_GREEN "%c", txt[i]);
	    else if(txt[i]== '[')
		printf(ANSI_COLOR_YELLOW "%c", txt[i]);
	    else if(txt[i]== '<')
		printf(ANSI_COLOR_BLUE "%c", txt[i]);
	    push(txt[i]); 
  	}
        /* If txt[i] is an ending parenthesis then pop from stack and  
          check if the popped parenthesis is a matching pair*/
        else if (txt[i] == '}' || txt[i] == ')' || txt[i] == ']' || txt[i] == '>') { 
  	    if(txt[i]== '}')
	    	printf(ANSI_COLOR_RED "%c", txt[i]);
	    else if(txt[i]== ')')
		printf(ANSI_COLOR_GREEN "%c", txt[i]);
	    else if(txt[i]== ']')
		printf(ANSI_COLOR_YELLOW "%c", txt[i]);
	    else if(txt[i]== '>')
		printf(ANSI_COLOR_BLUE "%c", txt[i]);	
            /*If we see an ending parenthesis without a pair then return false*/
            if (empty())
	    { 
                return 0;
		display(); 
  	    }
            /* Pop the top element from stack, if it is not a pair  
            parenthesis of character then there is a mismatch. 
            This happens for expressions like {(}) */
            else if (isMatchingPair(topelement(), txt[i])) 
            {
		pop();
	    	/*return 0; */
	    }
            else if (!isMatchingPair(topelement(), txt[i])) 
            {
		char lastbracket = topelement();
		if(lastbracket == '{')
	    	    printf(ANSI_COLOR_RED "\n    EXPECTED %c\n", '}');
	        else if(lastbracket == '(')
		    printf(ANSI_COLOR_GREEN "\n    EXPECTED %c\n", ')');
	        else if(lastbracket == '[')
		    printf(ANSI_COLOR_YELLOW "\n    EXPECTED %c\n", ']');
	        else if(lastbracket == '<')
		    printf(ANSI_COLOR_BLUE "\n    EXPECTED %c\n", '>');
	    	/*return 0; */
	    }
        }
	else if(txt[i] != '{' || txt[i] != '(' || txt[i] != '[' || txt[i] != '<' || txt[i] != '}' || txt[i] != ')' || txt[i] != ']' || txt[i] != '>')
	    printf(ANSI_COLOR_RESET "%c", txt[i]);
        i++; 
    } 
  
    /* If there is something left in expression then there is a starting 
      parenthesis without a closing parenthesis */
    if (empty()) 
        return 1; /*balanced*/
    else
        return 0; /*not balanced*/
} 
  
    

