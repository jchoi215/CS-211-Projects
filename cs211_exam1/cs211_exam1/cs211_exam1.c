//
//  Name: Jae Rim Choi
//  NetID: jchoi215
//  CS 211 EXAM 1
//

// The program will use one of the following:
//     - a queue implemented as a linked list
//     - a stack implemented as a linked list
//

// There are 5 operations you should be aware of:
//
// //  - initialization
// //  - add value (push for stack, enQueue "addToEnd" for the queue)
// //  - get value (top for stack, top for the queue)
// //  - remove value (pop for stack, dequeue "removeFromFront" for the queue)
// //  - isEmpty()

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct link{
  int value;
  struct link* connect;
} link;

#define QUEUE 0
#define STACK 1



// =============================================================================
//                            initialization
// =============================================================================
link* initialize(int value){
  link* temp = (link*) malloc( sizeof(link) );
  temp->value = value;
  temp->connect = NULL;
  return temp;
}



// =============================================================================
//                              isEmpty
// =============================================================================
bool isEmpty(link* list){
  if(list != NULL) return false;
  printf("   >> List is empty \n\n");
  return true;
}


// =============================================================================
//                            QUE & STACK: ADD
// =============================================================================
void enQueue(link** top, int value){

  link * temp = initialize(value);

  if( *top == NULL ) *top = temp;
  else
  {
    link* end = *top;
    while(end->connect != NULL)  end = end->connect;
    end->connect = temp;
  }
}


// =============================================================================
//                            QUE: REMOVE
// =============================================================================
void deQueue(link** top){
  if( isEmpty(*top) ) return;

  else{
      printf("   >> removing:  %d \n\n",(*top)->value);
      link * hold = *top;
      *top = (*top)->connect;
      free(hold);
  }
}


// =============================================================================
//                            STACK: REMOVE
// =============================================================================
void stack_remove(link** top){
    if(isEmpty(*top)) return;

    if( (*top)->connect == NULL )
    {
      printf("   >> removing:  %d \n\n",(*top)->value);
      free(top);
      *top = NULL;
      return;
    }

    else
    {
      link* end   = *top;
      link* trail = NULL;

      while(end->connect != NULL)
      {
        trail = end;
        end = end->connect;
      }

      printf("   >> removing:  %d \n\n", end->value);
      trail->connect = NULL;           free(end);
    }
}

// =============================================================================
//                                 DISPLAY
// =============================================================================
void show(link* top){
    printf("   >> [ FRONT <---- END ]: ");
    if( isEmpty(top) ) return;
    while(top != NULL){ printf("%d ", top->value); top = top->connect;}
    printf("\n\n");
}


// =============================================================================
//                          RETRIEVE QUEUE (0) / STACK (1)
// =============================================================================
void retrieve(link* list, int type){
  if( isEmpty(list) ) return;
  else
  {
      if(type)
        printf("   >> Top of stack:  %d \n\n", list->value );
      else
      {
        while(list->connect != NULL) list = list->connect;
        printf("   >> Top of Queue:  %d \n\n", list->value );
      }
  }
}


// =============================================================================
//                                 MAIN
// =============================================================================
int main(){


      link* top = NULL;

      int value;
      char instruction;

      printf("\n Instruction \n");
      printf(" Add:     a \n");
      printf(" Stack Remove:  1 \n");
      printf(" Queue Remove:  2 \n");
      printf(" Queue Retrieve 3 \n");
      printf(" Stack Retrieve 4 \n\n");
      printf(" Show:    s \n");
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
                        enQueue(&top, value);
                        break;

              // case 'b':
              //           printf("   >> Input value: ");
              //           scanf("%d",&value); getchar();
              //           printf("\n");
              //           enQueue(&top, value);
              //           break;


              case '1':
                        stack_remove(&top);
                        break;

              case '2':
                        deQueue(&top);
                        break;

              case '3':
                        retrieve(top, QUEUE);
                        break;

              case '4':
                        retrieve(top, STACK);
                        break;


              case 's':
                        show(top);
                        break;

              case 'q':
                        exit(1);
                        break;

              case '?':
                        printf("\n Instruction \n");
                        printf(" Add:     a \n");
                        printf(" Stack Remove:  1 \n");
                        printf(" Queue Remove:  2 \n");
                        printf(" Queue Retrieve 3 \n");
                        printf(" Stack Retrieve 4 \n\n");
                        printf(" Show:    s \n");
                        printf(" Quit:    q \n\n");
                        break;
          }

        printf("what would you like to do: ");
        scanf ("%c", &instruction); getchar();
        printf("------------------------------\n\n");
      }

  return 0;
}
