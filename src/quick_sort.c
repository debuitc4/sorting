/** quick_sort
 * Author: Caoimhe De Buitlear
 * References: https://www.geeksforgeeks.org/quick-sort/
*/
#include <stdio.h>
#include <stdlib.h>

/** Function Prototypes */
# include "sorting.h"

/** Function swap
* @params: pointer to integer and pointer to integer b
* returns: void
** description: swaps the two integers passed to it
**/

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

/** Function partition
* @params: array, lo integer, hi integer
* returns: partition
** description: this function partitions the array based on the pivot
**/

int partition(int nums[], int lo, int hi){
   int pivot = nums[hi];
   int i = (lo - 1);
   //loops through and checks if value is smaller than pivot
   int j=lo;
   while(j < hi){
      //puts elements smaller than the pivot on the left
      //and greater than the pivot on the right
      if (pivot >= nums[j]){
         i++;
         swap(&nums[j], &nums[i]);
      }
   j++;
   }
   swap(&nums[hi], &nums[i + 1]);
   return (i + 1);
}
/** Function quick_sort
* @params: array of integers, lo integer and hi integer
* returns: void
** description: sorts the array using quick sort algorithim
**/
void quick_sort(int * nums, int lo, int hi){
   if (hi > lo){
      int part = partition(nums, lo, hi);
      quick_sort(nums, lo, part - 1);
      quick_sort(nums, part + 1, hi);
   }
}
    