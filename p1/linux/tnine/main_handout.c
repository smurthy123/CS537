//******************************************************************************
// File owner: Suhasini Murthy
//------------------------------------------------------------------------------
// Description:

//******************************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "p1a2.h"

typedef int bool;
#define true 1
#define false 0 

/* This is an array of 10 POINTERS to KeyboardElements
*/

KEPtr keypad[10];
char 
*letters[10] = { "","","ABC","DEF","GHI","JKL", "MNO", "PQRS", "TUV", "WXYZ"};

//------------------------------------------------------------------------------
// Function needed to be provided to the printWrapper 
void PrintFunction(char c)
{
	printf("%c", c);
}

//------------------------------------------------------------------------------
// This function validates the input for all possible cases
bool isValid(int key, int hits){
  if (key > 1 && key < 10){
    if(((key == 7) || (key == 9)) && ((hits > 0) && (hits < 5))){
      return true;
    }
    else if ((hits > 0) && (hits < 4)){
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}


int main(int argc, char * argv[])
{

  int key_pressed, number_of_hits;
  int i;
  int j;

	if (argc <= 1)
	{
		printf("Usage: p1a2 string1 [stringN]\n");
		exit(1);
	}

  else {
    for (i = 0; i < 10 ; i++){
      keypad[i] = (KEPtr) malloc(sizeof(struct KeyboardElement));
      keypad[i]->counter = 0;
      keypad[i]->letters = letters[i];
    }
    
    for (i = 1; i < argc ; i++){
      //-----------------------Inner loop---------------------------------------
      for (j = 0; j < strlen(argv[1]) ; j = j+2){
        key_pressed    = argv[i][j] - 48;
        number_of_hits = argv[i][j+1] - 48 ;
        
        if (isValid(key_pressed, number_of_hits)){
          keypad[key_pressed] -> counter++;
          PrintWrapper(PrintFunction, 
                       keypad[key_pressed]->letters[number_of_hits-1]);
        }
        else {
          PrintWrapper(PrintFunction, '-');
          break; 
        } 
      }
      //------------------------------------------------------------------------
      PrintWrapper(PrintFunction, '\n');  
    }
  

    for (i = 2; i < 10 ; i++){   
      printf("%d\t%d\n",i,keypad[i]->counter);
    }
  
    for (i = 0; i < 10 ; i++){
      free(keypad[i]);
    }    
  }
	return 0;
}


