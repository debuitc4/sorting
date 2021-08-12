/** radix_half_sorted.h
 * Author: Caoimhe De Buitlear
*/
#include <stdio.h>
#include <stdlib.h>

/** Function Prototypes */
# include "sorting.h"

/** Function half_get_max
* @params: integer array a, integer n
* returns: max (integer)
** description: The get_max function finds the maximum value
** in the array and then returns it
**/

int half_get_max(int a[], int n){
   int max = a[0];
   for (int i = 1; i< n; i++){
      if (a[i] > max)
         max = a[i];
   }
   return max;
}

/** Function half_count_sort
* @params: int array a, int len, and int place
* returns: void
** description: used to sort elements by counting the number of
** occurances of each unique element in the array
**/

void half_count_sort(int a[], int len, int place) {
  //assigning memory to out array
  int *out = (int*) malloc(len*sizeof(int)); 
  int i, count[10] = {0};
  //store the count of occurrences of each element in count
  for (i = 0; i < len; i++)
    count[(a[i] / place) % 10]++;
  
  //store the cummulative count
  for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
  // get index of each element from the original array in count array
  // put these elements in the output array
  for (i = len - 1; i >= 0; i--) {
    out[count[(a[i] / place) % 10] - 1] = a[i];
    count[(a[i] / place) % 10]--;
    }
  //copy each of the sorted elements into the original array
  for (i = 0; i < len; i++)
    a[i] = out[i];
}

/** Function half_radix_sort
* @params: pointer to integer array a, integer len
* returns: void
** description: used to implement the radix sort algorithim on half
** the array. (i.e. half sorted half not sorted)
**/

void half_radix_sort(int * a, int len) {
  int half_len = len / 2;
  // uses the get_max function to get the max integer
  int max = get_max(a, half_len);
  int exp;
  //implements the count sort algorithm based on place value
  for (exp = 1; max / exp > 0; exp *= 10)
    count_sort(a, half_len, exp);
}
