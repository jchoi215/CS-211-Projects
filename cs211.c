#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct linkedStruct
{
 int elem;
 struct linkedStruct*  next;
};

typedef struct linkedStruct linked;
typedef linked* linkedPtr;

void insertAtFront (linked** hd, int val){

     /* create the new node */
     linked* ptr = (linked*) malloc (sizeof(linked));

     /* store information into the new node  */
     ptr->elem = val;
     ptr->next = *hd;

     /* update the head of the list to refer to the new node */
     *hd = ptr;
    }

    linked* insertAtFront2 (linked* hd, int val)
    {
     /* create the new node */
     linked* ptr = (linked*) malloc (sizeof(linked));

     /* store information into the new node  */
     ptr->elem = val;
     ptr->next = hd;

     /* update the head of the list to refer to the new node */
     hd = ptr;

     /* return the newly updated head of list */
     return hd;
}


void insertAtEnd (linked** hd, int val){

 linked* curr = *hd;
 linked* prev = NULL;

 /* find the end of the list */
 while (curr != NULL)
   {
    prev = curr;
    curr = curr->next;
   }

 /* create the new node to be inserted into the list */
 linked* ptr = (linked*) malloc (sizeof(linked));
 ptr->elem = val;
 ptr->next = curr;   /* curr is always NULL at this line of code */

 /* if the list is empty the new node goes at the front (update head) */
 if (prev == NULL)
   {
    *hd = ptr;
   }
 else
   {
    prev->next = ptr;
   }
}


linked* insertAtEnd2 (linked* hd, int val){    // ==========   THIS WAS ADDED

   linked* curr = hd;
   linked* prev = NULL;

   /* find the end of the list */
   while (curr != NULL)
     {
      prev = curr;
      curr = curr->next;
     }

   /* create the new node to be inserted into the list */
   linked* ptr = (linked*) malloc (sizeof(linked));
   ptr->elem = val;
   ptr->next = curr;   /* curr is always NULL at this line of code */

   /* if the list is empty the new node goes at the front (update head) */
   if (prev == NULL)
     {
      hd = ptr;
     }
   else
     {
      prev->next = ptr;
     }

   return hd;
}


void insertInOrder (linked** hd, int val){

 linked* curr = *hd;
 linked* prev = NULL;

 /* set curr to refer to the node in the list that is >= val */
 /*   prev will be set to the node just before curr */
 while ((curr != NULL) && (curr->elem < val))
   {
    prev = curr;
    curr = curr->next;
   }

 /* create the node to add into the list */
 linked* ptr = (linked*) malloc (sizeof(linked));
 ptr->elem = val;
 ptr->next = curr;

 /* if prev is null, insert at the front of the list */
 if (prev == NULL)
   {
    *hd = ptr;
   }
 else
   {  /* otherwise insert right after prev */
    prev->next = ptr;
   }
}


linked* insertInOrder2 (linked* hd, int val){  // ============  THIS WAS ALSO ADDED

    linked* curr = hd;
    linked* prev = NULL;


    while ((curr != NULL) && ( val > curr->elem ))
    {
     prev = curr;
     curr = curr->next;
    }

    linked* ptr = (linked*) malloc (sizeof(linked));
    ptr->elem = val;
    ptr->next = curr;

    if (prev == NULL)  return ptr;
    else
    {
      prev->next = ptr;
      //if(curr != NULL) ptr->next = curr;
    }


    return hd;
}


void show (linked* hd){

   while (hd != NULL)
     {
      printf ("%d, ", hd->elem);
      hd = hd->next;
     }
   printf ("\n");
}


int listLength (linked* hd){
 int length = 0;
 while (hd != NULL)
   {
    length++;
    hd = hd->next;
   }
 return length;
}


int main (int argc, char**argv)
{
  linked* head = NULL;
  int i;
  int temp;

  for (i = 0 ; i < SIZE; ++i)
    {
     temp = rand() % 100;
     printf ("In main(): temp: %6d\n", temp);

     // ==================   select which one you want to use  ==============

      // insertAtFront (&head, temp);            // allocate new node, insert value, connect to old head pointer, set pointer to the new NODE as the head in the function
      // head = insertAtFront2 (head, temp);     // allocate new node, insert value, connect to old head. RETURN the new NODE pointer to main where it is used as the new HEAD
      // insertAtEnd (&head, temp);              // given
      // head = insertAtEnd2 (head, temp);       // checked **
      // insertInOrder (&head, temp);            // given
       head = insertInOrder2 (head, temp);     // checked **

     show (head);
     printf ("The list has %d nodes\n", listLength(head));
    }

  printf ("\n");
}
