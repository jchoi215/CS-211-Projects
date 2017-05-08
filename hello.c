#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main(){


// integer variable called myint
// character variable called mychar
// an integer pointer called myptr
//
// Add code to your hello.c program to
// Print out the "size"  (in bytes) of each of these variables.
// Print (out in decimal and hexadecimal) the largest decimal value that each of these can hold

 printf("Hello World\n\n");
 printf("NetID: jchoi215\n\n");

 int myint;
 char mychar;
 int* myptr;


  printf("myint: %d\n", sizeof(myint));
  printf("mychar: %d\n", sizeof(mychar));
  printf("myptr: %d\n\n\n", sizeof(myptr));



  printf("decimal values: \n");
  printf("myint: %d\n", INT_MAX);
  printf("mychar: %d\n", CHAR_MAX);
  printf("myptr: %d\n\n\n", INTPTR_MAX);


  printf("hexadecimal values: \n");
  printf("myint: %x\n", INT_MAX);
  printf("mychar: %x\n", CHAR_MAX);
  printf("myptr: %x\n\n\n",INTPTR_MAX);
  
  printf("hexadecimal +1 values: \n");
  printf("myint: %x\n", INT_MAX+1);
  printf("mychar: %x\n", CHAR_MAX+1);
  printf("myptr: %x\n\n\n",INTPTR_MAX+1);


  return 0;
}
