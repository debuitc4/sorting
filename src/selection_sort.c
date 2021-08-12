/** selection_sort
 * Author: Caoimhe De Buitlear
 * References: https://www.programmingsimplified.com/c/source-code/c-program-selection-sort
*/
#include <stdio.h>
#include <stdlib.h>

/** Function Prototypes */
# include "sorting.h"

/** Function selection_sort
* @params: length of array and pointer to integer array
* returns: void
** description: uses selection sort to sort array
**/

void selection_sort(int len, int * a)
{
  //initalizing variables
  int n, i, j, position, swap;
  //looping through and swapping values using selection sort
  for (i=0; i < len; i++){
    position = i;
    for (j = i + 1; j < len; j++){
      if(*(a + position) > *(a + j))
        position = j;
    }
    if(position != i){
      *(a + i) += *(a + position);
      *(a + position) = *(a + i) - *(a + position);
      *(a + i) -= *(a + position);
    }
  }
}