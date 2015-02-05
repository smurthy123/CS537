//******************************************************************************
// File owner: Suhasini Murthy
//------------------------------------------------------------------------------
// Description:
//

#include<stdio.h>
#include<stdlib.h>

int 
main(int argc, char* argv[]){
  
  int input_argument;
  int* memory_pointer;
  int position;
  int row_num, column_num;

  if (argc <=1){
    input_argument = 10;
  }
  else {
    input_argument = atoi(argv[1]);
    if (input_argument < 1 || input_argument > 10){
      input_argument = 10;
    }
  }
 
  memory_pointer = (int*)malloc(sizeof(int)*input_argument*input_argument) ;

  for(row_num = 0 ; row_num < input_argument ; row_num++ ) {
    for(column_num = 0 ; column_num < input_argument ; column_num++ ) {
      position = (row_num * input_argument) + column_num ;  
      (*(memory_pointer + position)) = (row_num + 1) * (column_num + 1);
      printf("%d\t",(*(memory_pointer + position)));
    }
    printf("\n");
  } 

  free(memory_pointer);

  return 1;

}   
