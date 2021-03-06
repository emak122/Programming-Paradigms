/* Program to find the smallest positive missing number */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_set> 
using namespace std;

/*

Naive Approach 
int findMissing(int arr[],int n){

  unordered_set <int> set;

  for(int i=0 ;i<n; i++)
    set.insert(arr[i]);


  for(int i=1;i<n;i++)
  {
      if(set.find(i) == set.end()){

         return i;
      }

  }

}

*/

/* Program to find the smallest positive missing number */
#include <stdio.h>
#include <stdlib.h>
 
/* Utility to swap to integers */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
 

int segregate(int arr[],int size){

  int j=0;
    for(int i = 0; i < size; i++){

        if(arr[i] < 0){

            swap(&arr[i],&arr[j]);
            j++;
        }
    }

    return j;
}

int findMissingPositive(int arr[],int size){
// //Mark arr[i] visited by changing sign of arr[arr[i] - 1 ] to negative;

    for(int i = 0; i < size; i++){


      // Algorithm !
      
        if(abs(arr[i] - 1) < size && arr[abs(arr[i]) - 1] > 0){
          arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }

    }

    for(int i = 0; i < size; i++){

      if(arr[i] > 0)
        return i+1;
    }

    return size + 1;
}

 
// /* Find the smallest positive missing number in an array that contains
//   both positive and negative integers */
int findMissing(int arr[], int size)
{
   // First separate positive and negative numbers
   int shift = segregate (arr, size);
 
   // Shift the array and call findMissingPositive for
   // positive part

   int positive = findMissingPositive(arr+shift,size-shift);
   return positive;
   
}


/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */


int Naive_approach(int arr[],int size){

  unordered_set <int> set;


  for(int j=0;j<size;j++){
    set.insert(arr[j]);
  }

  for(int j=0;j<size;j++){
      
      if(set.find(j) == set.end()){
          return j;
      }
  }

}


int main()
{
  int arr[] = {0, 10, 2, -10, -20};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  int missing = Naive_approach(arr, arr_size);
  printf("The smallest positive missing number is %d \n", missing);
 
  return 0;
}