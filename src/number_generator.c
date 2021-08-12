/** number_generator
 * Author: Caoimhe De Buitlear
 * References: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
 * https://www.geeksforgeeks.org/generating-random-number-range-c/
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/** Function Prototypes */
# include "number_generator.h"

/** Function num_gen
* @params: integer array "array", integer "numb"
** returns: random numbers
** description: This function generates random 
** numbers (number given on command line), between one and ten.
** It then outputs these numbers to a file and adds them to an array.
**/

int num_gen(int array[], int numb) {
   int i, n;
   FILE * fp;
   //open the file for writing
   fp = fopen("text.txt", "w");

   /* this srand function makes sure 
      my program outputs different nunbers
      each time */
   srand(time(0));
   //generating random numbers
   for (i = 0; i < numb; i++) {
      n = rand() % 100 + 1;
      array[i] = n;
      fprintf(fp, "%d\n", n);
  }
   fclose (fp);
}
