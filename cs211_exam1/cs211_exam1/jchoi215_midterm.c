
//
//  Name: Jae Rim Choi
//  NetID: jchoi215
//  UIN: 671239553
//  CS 211 EXAM
//



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct link{
  int value;
  struct link* connect;
} link;




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
  return true;
}


// =============================================================================
//                           STACK: ADD
// =============================================================================
void push(link** top, int value){

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
//                          RETRIEVE  STACK
// =============================================================================
void top(link* list){
  if( isEmpty(list) ) return;
  else
  {
    while(list->connect != NULL) list = list->connect;
    printf("%d ", list->value);
  }
}


// =============================================================================
//                            STACK: REMOVE
// =============================================================================
void pop(link** top){

    if(isEmpty(*top))  return;

    if( (*top)->connect == NULL )
    {
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

      trail->connect = NULL;
      free(end);
    }
}



// =============================================================================
//                       COMBINE TOP + POP
// =============================================================================
void popDisplay(link ** list){
  while( !isEmpty(*list) ){
    top(*list);
    pop(list);
  }
}



// =============================================================================
//                                  MAIN
// =============================================================================
int main(){

    link* even = NULL;
    link* odd  = NULL;
    link* div3 = NULL;

    int value;

     fscanf (stdin, "%d", &value);
     while(value > 0  )   // read till EOF
     {
       if(value % 2 == 0) push(&even, value);
       if(value % 2 == 1) push(&odd, value);
       if(value % 3 == 0) push(&div3, value);

       fscanf (stdin, "%d", &value);
     }

    printf("\n\nEven values in reverse order: \n");
    popDisplay(&even);

    printf("\n\nOdd values in reverse order: \n");
    popDisplay(&odd);

    printf("\n\nThe Multiples of 3 in reverse order: \n");
    popDisplay(&div3);

    printf("\n\n");
    return 0;
}
