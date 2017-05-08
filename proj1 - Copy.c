#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// values are taken into the system
// the newly created int pointer - would be returned into the system
// thus ---> keep track of the newly incoming ---- index values ---
// Another pointer is created into the system -->>
// >> thus there is 2 functions with same index ---
// now take the 2 values of the system which -- take those values and switch
// --- sort the system into file ----  quick sort would be prefered --

void binearySearch(int Array[], int find, int limit){
   int index = -999;
   int low = 0;
   int mid = 0;
   int high = limit;
   int numComparison = 1;

   clock_t startClock;
   clock_t endTime;

   startClock = clock();
   while(high >= low)
   {
     ++numComparison;
     mid = (high + low) /2;
     if(Array[mid] < find) low = mid+1;
     else if(Array[mid] > find) high = mid-1;
     else if(Array[mid] == find)
     {
      index = mid;
      break;
     }
   }
   endTime = clock();

   if(index == -999)
   {
     printf("value: %d was NOT found in the array\n", find);
     printf("Number of comparison: %d\n",numComparison );
     printf("Time it took: %d\n\n",endTime);
   }
   else
   {
     printf("value: %d  is located in %d\n", find, index);
     printf("Number of comparison: %d\n",numComparison );
     printf("Time it took: %d\n\n",endTime);
   }
}

void linearSearch(int Array[], int find, int limit){
     int numComparison = 1;
     int index = -999;
     int i = 0;
     clock_t startTime;
     clock_t endTime;

     startTime = clock();
     for(i = 0 ; i < limit; ++i){
       if(Array[i] == find)
       {
         index = i;
         numComparison = i;
         break;
       }
       else
       {
         ++numComparison;
       }
     }
     endTime = clock();


     if(index == -999)
     {
       printf("value: %d was NOT found in the array\n", find);
       printf("Number of comparison: %d\n",numComparison );
       printf("Time it took: %d\n\n",endTime);
     }
     else
     {
       printf("value: %d  is located in %d\n", find, index);
       printf("Number of comparison: %d\n",numComparison );
       printf("Time it took: %d\n\n",endTime);
     }
}

int getInput(){
  int input = 0;
  char returnChar;
  printf("Please input value to search: ");
  scanf("%d%c", &input, &returnChar);
  return input;
}

int partition(int incomingArray[], int start, int end){

   int left = start;
   int right = end;
   int temp;
   bool finished = false;

   int mid = start + (end - start) / 2;
   int pivot = incomingArray[mid];

   while(!finished){

     while( incomingArray[left]  < pivot ) ++left;
     while( incomingArray[right] > pivot) --right;

     if(left >= right) finished = true;

     else
     {
       temp = incomingArray[left];
       incomingArray[left] = incomingArray[right];
       incomingArray[right]= temp;

       ++left;
       --right;
     }
   }

   return right;
}

void quickSort(int incomingArray[], int start, int finalIndex){

    if(start>= finalIndex) return;

    int mid = partition(incomingArray,start, finalIndex);
    quickSort(incomingArray, start, mid);
    quickSort(incomingArray, mid+1, finalIndex);

}

int * copyArray(int oldArray[], int size, int limit){

  int * duplicateArray =  (int *) malloc (size * sizeof(int));

  int i = 0;
  for(i = 0; i < limit; ++i){
      duplicateArray[i] = oldArray[i];
  }

  return duplicateArray;
}

int* transferData(int *incoming, int limit, int newSize){

  int * newArray =  (int *) malloc (newSize * sizeof(int));

  int i = 0;
  for(i = 0; i < limit; ++i){
      newArray[i] = incoming[i];
  }

  return newArray;
}


int* insertValue(int* size, int* finalIndex){


    int * tempArray =  (int *) malloc (*size * sizeof(int));

   printf("\n ** INPUT SYSTEM ** \n ");
   printf(" Input value into the system (-999 to end input)\n >>");

   int index = 0;
   bool finished = false;


   while(!finished)
   {
          int input = 0;
          int rKey = 0;
          scanf("%d%c",&input,&rKey);
          if(input == -999 || rKey == -999) finished = true;
          else if(index >= *size){

              int prevSize = *size;
              *size = *size * 2;
              tempArray = transferData(tempArray, prevSize, *size);
              tempArray[index] = input;
              ++index;

          }
          else
          {
            tempArray[index] = input;
            ++index;
          }
   }

  * finalIndex = index;
  return tempArray;
}

int main(){

  int limit = 2;
  int finalIndex = 2;

  int* originalArray;
  originalArray = insertValue(&limit, &finalIndex);

  int * duplicateArray = copyArray(originalArray,limit, finalIndex);
  printf("Sorting the system values...\n");
  quickSort(duplicateArray, 0, finalIndex-1);
  int userInput = getInput();


            int i = 0;


            printf("Display original array: \n");
            for(i = 0; i < finalIndex; i++)
            {
             printf("%d \n", originalArray[i]);
            }


            printf("Sort copied array: \n");
            for(i = 0; i < finalIndex; i++)
            {
             printf("%d \n", duplicateArray[i]);
            }



  linearSearch(duplicateArray,userInput, finalIndex);
  binearySearch(duplicateArray,userInput, finalIndex-1);


  // using the time.h catagory for time basis in the system
  // clock_t startTime = clock();
  // clock_t endTime = clock();
  // notice that system just needs to be called again for the system to stop


  // int i = 0;
  //
  //
  // printf("Display original array: \n");
  // for(i = 0; i < finalIndex; i++)
  // {
  //  printf("%d \n", originalArray[i]);
  // }
  //
  //
  // printf("Sort copied array: \n");
  // for(i = 0; i < finalIndex; i++)
  // {
  //  printf("%d \n", duplicateArray[i]);
  // }




  //  printf("Number of index: %d", limit);
  //  printf("Number current stading index: %d", finalIndex);

  // I prefer to create the new point with the correct set of memory location


  //ArrayCopy();
return 0;
}
