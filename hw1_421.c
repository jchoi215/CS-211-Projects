/* main.c */

/*
* complete AVL insert:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


typedef int AVLElementType;

typedef struct AVLNode
{
  AVLElementType   value;
  int              height;
  struct AVLNode  *left;
  struct AVLNode  *right;
} AVLNode;

//
// helper functions for height and max:
//
int _height(AVLNode *N)
{
  if (N == NULL)
    return -1;
  else
    return N->height;
}

int _max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}


//
// AVL Insert:
//
// Inserts the given value into the AVL tree, rebalancing
// the tree as necessary.  Returns a pointer to the root of
// the new tree; if the value to insert is already in the
// tree, nothing happens and a pointer to the root of the
// original tree is returned.
//
//


// MY WAY OF CREATING THE PROPER --------------------------------

int Height(AVLNode *root){
    if(root == NULL) return -1;
    else
    {
       int left = Height(root->left);
       int right= Height(root->right);
       if(left > right) return left+1;
       else return right+1;
    }
}

void freeIt(AVLNode *stack[], int *top){
  if(*top == -1) return;
  stack[*top] = '\0';
  *top -= 1;
  freeIt(stack, top);
}

void pushStack(AVLNode *stack[],int *top, AVLNode *location)
{
  if(location == NULL) return;
  *top += 1;
  stack[*top] = location;
}






AVLNode *doubleLeft(AVLNode *A)
{
  AVLNode  *B  = A->right;
  AVLNode  *C  = B->left;
  AVLNode  *CL = C->right;
  AVLNode  *CR = C->left;

  C->left  = A;
  A->right   = CR;
  C->right   = B;
  B->left  = CL;

  // // Update heights
  A->height = Height(A);
  B->height = Height(B);
  C->height = Height(C);

  // Return new root
  return C;
}


AVLNode *doubleRight(AVLNode *A)
{
    AVLNode  *B  = A->left;
    AVLNode  *C  = B->right;
    AVLNode  *CL = C->left;
    AVLNode  *CR = C->right;

    C->right  = A;
    A->left   = CR;
    C->left   = B;
    B->right  = CL;

    // // Update heights
    A->height = Height(A);
    B->height = Height(B);
    C->height = Height(C);

    // Return new root
    return C;
}


AVLNode *rightRotate(AVLNode *A)
{
    // save all points
    AVLNode  *B  = A->left;
    AVLNode  *C  = B->right;

     B->right = A;
     A->left = C;


    // Update heights
    A->height = Height(A);
    B->height = Height(B);

    // Return new root
    return B;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
AVLNode *leftRotate(AVLNode *A)
{
  AVLNode  *B  = A->right;
  AVLNode  *C  = B->left;

   B->left = A;
   A->right = C;

  // Update heights
  A->height = Height(A);
  B->height = Height(B);

  // Return new root
  return B;
}









AVLNode *Insert(AVLNode *root, AVLElementType value, AVLNode *stack[], int * top)
{
  AVLNode *prev = NULL;
  AVLNode *cur = root;

  while (cur != NULL)
  {
    if (cur->value == value)  return root;
    else if (value < cur->value)  // smaller, go left:
    {
      prev = cur;
      cur = cur->left;
      pushStack(stack, top, prev);
      prev->height = Height(prev);
    }
    else
    {
      prev = cur;
      cur = cur->right;
      pushStack(stack, top, prev);
      prev->height = Height(prev);
    }
  }

  AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
  newNode->value = value;
  newNode->height = 0;
  newNode->left = NULL;
  newNode->right = NULL;

  if (prev == NULL)  root = newNode;
  else if (value < prev->value)  prev->left = newNode;
  else prev->right = newNode;
  int brokenAvlFound = 0;


    int i;
    for(i = *top; i >= 0; --i)
    {
      int prevHeight = stack[i]->height;
      if(Height(stack[i]) == prevHeight)  break; // when the height is not update
      else if( abs(Height(stack[i]->left) - Height(stack[i]->right) ) > 1)
      {
        brokenAvlFound = 1;  // THIS IS the breaking case when it becomes unbalanced
        break;
      }
      stack[i]->height = Height(stack[i]);
    }

  //if(brokenAvlFound == 1) printf(" ===========  broken point is: %d\n", stack[i]->value);

    if(brokenAvlFound)
    {
      if( Height(stack[i]->left) > Height(stack[i]->right) )
      {
      //  printf("THIS IS THE LEFT SIDE...");
        if(Height(stack[i]->left->left) > Height(stack[i]->left->right))
        {
          //printf("did it go here?");
          if(i != 0)
          {
            AVLNode *temp =  rightRotate(stack[i]);
            if(stack[i-1]->value > temp->value)
            stack[i-1]->left   = temp;     // LEANING LEFT  --- so rotate RIGHT
            else
            stack[i-1]->right   = temp;     // LEANING LEFT  --- so rotate RIGHT
          }
          else root = rightRotate(stack[i]);
        }
        else
        {
            //printf("RIGHT");
            if(i==0)
            {
              root =  doubleRight(stack[i]);
            }
            else
            {
              AVLNode *temp =  doubleRight(stack[i]);
              if(stack[i-1]->value > temp->value)
              stack[i-1]->left   = temp;     // LEANING LEFT  --- so rotate RIGHT
              else
              stack[i-1]->right   = temp;     // LEANING LEFT  --- so rotate RIGHT
            }
        }
      }
      else // this would be the  right side rotation
      {
          //printf("THIS IS THE RIGHT SIDE...");
          if(Height(stack[i]->right->right) > Height(stack[i]->right->left))
          {
            if(i != 0)
            {
              AVLNode *temp =  leftRotate(stack[i]);
              if(stack[i-1]->value < temp->value)
              stack[i-1]->right   = temp;     // LEANING LEFT  --- so rotate RIGHT
              else
              stack[i-1]->left    = temp;     // LEANING LEFT  --- so rotate RIGH
            }
            else root = leftRotate(stack[i]);
          }
          else
          {

            if(i == 0) root = doubleLeft(stack[i]);
            else
            {
              AVLNode *temp =  doubleLeft(stack[i]);
              if(stack[i-1]->value > temp->value)
              stack[i-1]->left   = temp;     // LEANING LEFT  --- so rotate RIGHT
              else
              stack[i-1]->right   = temp;     // LEANING LEFT  --- so rotate RIGHT
            }

          }
        }

        int k;
        for(k = i; k >= 0; --k )
        {
          stack[k]->height = Height(stack[k]);
        }

    }



    freeIt(stack, top);  // free the stack after all the issues are dealth with;


  return root;
}

//
// Returns true (non-zero value) if the given binary tree is a
// binary search tree; returns false (0) if not.
//
#define TRUE  1
#define FALSE 0

int _allSubtreeValuesAreLess(AVLNode *root, AVLElementType value)
{
  if (root == NULL)
    return TRUE;
  else
  {
    return root->value < value &&
      _allSubtreeValuesAreLess(root->left, value) &&
      _allSubtreeValuesAreLess(root->right, value);
  }
}

int _allSubtreeValuesAreGreater(AVLNode *root, AVLElementType value)
{
  if (root == NULL)
    return TRUE;
  else
  {
    return root->value > value &&
      _allSubtreeValuesAreGreater(root->left, value) &&
      _allSubtreeValuesAreGreater(root->right, value);
  }
}

int isBST(AVLNode *root)
{
  if (root == NULL)
    return TRUE;
  else
  {
    return _allSubtreeValuesAreLess(root->left, root->value) &&
      _allSubtreeValuesAreGreater(root->right, root->value) &&
      isBST(root->left) &&
      isBST(root->right);
  }
}


//
// Returns true (non-zero value) if the given binary tree is an
// AVL tree; returns false (0) if not.
//
int _checkAllSubtreeHeights(AVLNode *root)
{
  if (root == NULL)
    return TRUE;
  else
  {
    // let's also make sure the heights are correctly computed:
    int hl = _height(root->left);
    int hr = _height(root->right);
    int H = 1 + _max(hl, hr);

    return (H == root->height) &&
      (abs(_height(root->left) - _height(root->right)) <= 1) &&
      _checkAllSubtreeHeights(root->left) &&
      _checkAllSubtreeHeights(root->right);
  }
}

int isAVL(AVLNode *root)
{
  if (root == NULL)
    return TRUE;
  else
  {
    return isBST(root) &&
      _checkAllSubtreeHeights(root);
  }
}


AVLNode *BuildTree(FILE *input, AVLNode *stack[], int * top)
{
  AVLNode  *root = NULL;
  int       value;

  fscanf(input, "%d", &value);

  while (value != 0)  // until we see EOF marker
  {
    printf(">> Inserting %d...\n", value);

    root = Insert(root, value, stack, top);

    fscanf(input, "%d", &value);
  }

  // done:
  return root;
}


void PrintPreorder(AVLNode *root)
{
  if (root == NULL)
    return;

  printf("(%d,%d);", root->value, root->height);
  PrintPreorder(root->left);
  PrintPreorder(root->right);
}


int main()
{
  AVLNode *root;
  FILE    *input;

  AVLNode *stack[64];
  int      top = -1;

  input = stdin;

  root = BuildTree(input, stack, &top);

  printf("**Tree before rotate: ");
  PrintPreorder(root);
  printf("\n");

  int value;
  fscanf(input, "%d", &value);

  root = Insert(root, value, stack, &top);

  printf(">> Inserting %d...\n", value);

  printf("**Tree after rotate:  ");
  PrintPreorder(root);
  printf("\n");

  printf("** IsBST? %s\n", isBST(root) ? "yes" : "no");
  printf("** IsAVL? %s\n", isAVL(root) ? "yes" : "no");

  return 0;
}
