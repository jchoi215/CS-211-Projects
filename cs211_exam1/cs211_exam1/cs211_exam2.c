
//
//  Name: Jae Rim Choi
//  NetID: jchoi215
//  CS 211 EXAM 1
//
//     - a queue implemented as a dynamic array
//     - a stack implemented as a dynamic array
//
// There are 5 operations you should be aware of:
//
// //  - initialization
// //  - add value (push for stack, enQueue "addToEnd" for the queue)
// //  - get value (top for stack, top for the queue)
// //  - remove value (pop for stack, dequeue "removeFromFront" for the queue)
// //  - isEmpty()


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE 0
#define STACK 1

typedef struct stack{
  int * array;
  int size;
  int top;
} stack;


// =============================================================================
//                                initialize
// =============================================================================
void initialize(stack * box){
  box->size = 2;
  box->top  = -1;
  box->array = (int*) malloc ( box->size * sizeof(int));
}


// =============================================================================
//                            dynamic array growth
// =============================================================================
void resize(stack* box, int value){
  int * newArray = (int* ) malloc ( 2 * box->size * sizeof(int));
  int i;
  for(i = 0; i < box->size; ++i) newArray[i] = box->array[i];
  newArray[box->size] = value;

  int * deletion = box->array;
  box->array = newArray;
  box->size *= 2;
}

// =============================================================================
//                                   push
// =============================================================================
void push(stack* box, int value){
  box->top += 1;
  if(box->top >= box->size)
      resize(box, value);
  else
      box->array[box->top] = value;
}

// =============================================================================
//                                  display
// =============================================================================
void display(stack * box){
  int i;
  printf(" Values that are held in the array:\n\n >> ");
  for(i = 0; i <= box->top; ++i) printf("%d ", box->array[i]);
  printf("\n\n");
}


// =============================================================================
//                                 isEmpty
// =============================================================================
bool isEmpty(int value){
  if(value > 0) return false;
  printf(" List is currently empty\n\n");
  return true;
}

// =============================================================================
//                               queue remove
// =============================================================================
void queueRemove(stack * box){
  int i;
  if( isEmpty(box->top) ) return;
  else{
      printf("   >> Removing: %d\n\n", box->array[0] );
      for(i = 1; i <= box->top; i++) box->array[i - 1] = box->array[i];
      box->top -= 1;
  }
}

// =============================================================================
//                               stack remove
// =============================================================================
void stackRemove(stack * box){
  if( isEmpty(box->top) ) return;
  else
  {
    printf("   >> Removing: %d\n\n", box->array[box->top] );
    box->top -= 1;
  }
}

// =============================================================================
//                         QUEUE & STACK RETRIEVE
// =============================================================================
void retrieve(stack* box, int type){
  if( isEmpty(box->top) ) return;
  else{
    (type)?  printf("   >> Stack top: %d\n\n", box->array[box->top] ):
             printf("   >> Queue top: %d\n\n", box->array[0] );
  }
}


// =============================================================================
//                                 MAIN
// =============================================================================
int main(){

  stack * box = (stack*) malloc (sizeof(stack));
  initialize(box);
  // printf("%d", box->size);

  int value;
  char instruction;

  printf("\n Instruction \n");
  printf(" Add:     a  \n");
  printf(" Queue Remove:  1  \n");
  printf(" Stack Remove:  2  \n\n");
  printf(" Queue Retrieve:  3  \n");
  printf(" Stack Retrieve:  4  \n\n");

  printf(" Show:    s \n");
  printf(" More:    ? \n");
  printf(" Quit:    q \n\n");

  printf("What would you like to do: ");
  scanf ("%c", &instruction);
  printf("------------------------------\n\n");


  while(1)
  {
    switch(instruction)
    {
      case 'a':
                printf("   >> Input value: ");
                scanf("%d",&value); getchar();
                printf("\n");
                push(box, value);
                break;

      case '1':
                queueRemove(box);
                break;

      case '2':
                stackRemove(box);
                break;

      case '3':
                retrieve(box,QUEUE);
                break;

      case '4':
                retrieve(box,STACK);
                break;

      case 's':
                display(box);
                break;

      case '?':
                printf("\n Instruction \n");
                printf(" Add:     a  \n");
                printf(" Queue Remove:  1  \n");
                printf(" Stack Remove:  2  \n\n");
                printf(" Queue Retrieve:  3  \n");
                printf(" Stack Retrieve:  4  \n\n");

                printf(" Show:    s \n");
                printf(" More:    ? \n");
                printf(" Quit:    q \n\n");
                break;

      case 'q':
                exit(1);
                break;

      }

    printf("what would you like to do: ");
    scanf ("%c", &instruction); getchar();
    printf("------------------------------\n\n");
  }

  return 0;
}
