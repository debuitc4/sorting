/** half_and_half
 * Author: Caoimhe De Buitlear
 * References: https://www.decodeschool.com/C-Programming/Arrays/C-Program-to-sort-half-of-the-Array-elements-in-ascending-order-and-next-half-in-descending-order
*/
#include <stdio.h>
#include <stdlib.h>

/** Function Prototype for num_gen */
# include "datasets.h"

/** Function half_and_half
* @params: length of array and pointer to intger array
* returns: void
** description: this function sorts half the array in ascending order and
** the second half in descending order
**/

void half_and_half(int len, int * arr){
   int i,j,temp;
   for(i=0;i<len;i++)
	{
		//this loop does the first half of the array in ascending order
		for(j=0; j<len/2;j++)
		{
			if(arr[j+1] < arr[j])
			{
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] -= arr[j + 1];
			}
		}
		//this loop does the second half of the array in descending order
		for(j=len/2;j<len-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] -= arr[j + 1];
			}
		}
	}
}
