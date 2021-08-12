/** rev_radix_sort.h
 * Author: Caoimhe De Buitlear
 * references: https://www.tutorialspoint.com/c-program-for-radix-sort
*/

#include <stdio.h>
#include <stdlib.h>

/** Function Prototypes */
# include "sorting.h"


/** Function rev_RadixSort
* @params: pointer to integer array a, integer n
* returns: void
** description: this function sorts the array in descending order using radix sort
**/

void rev_RadixSort (int * a, int n){
    //allocating memory to array
    int *b_new = (int*) malloc(n*sizeof(int)); 
    int i, j = 0, exp = 1;
    for (i = 0; i < n; i++)
        //looping through, if element at a[i] is larger than j, swap
        if (a[i]>j){
            j = a[i];
        }
    //this loop controls exp which grows by *10 each time
    while (j / exp > 0)
    {
        //creating the buckets that the numbers will be sorted into
        //based on their LSD (least significant digit)
        
        // 10 buckets in total (0-9)
        int buck[10]={0};
        //creates the counts for each bucket
        for (i=0; i < n; i++){
            buck[9 - a[i] / exp % 10]++;
        }
        for (i=1; i<10; i++){
            buck[i] += buck[i-1];
        }
        //puts the numbers into their respective buckets
        for (i = n-1; i >= 0; i--){
            b_new[--buck[9-a[i]/exp%10]] = a[i];
        }
        for (i = 0; i < n; i++){
            a[i] = b_new[i];
        }
        //increase the place value
        exp *= 10;
    }
}