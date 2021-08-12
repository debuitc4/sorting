/** main_prog
 * Author: Caoimhe De Buitlear
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// header files
#include "number_generator.h"
#include "sorting.h"
#include "datasets.h"

/** Function Prototypes */
int main(int argc, char *argv[]);

int main(int argc, char *argv[]){
   //Allocating memory to the array
   int x = atoi(argv[1]);
   int* number_array = (int *)malloc(x * sizeof(int));
   if (number_array == NULL) {
    printf("malloc failed\n");
    return -1;}
    else{
      printf("Memory allocated successfully.\n");
    }

   //Letting the user choose what dataset to sort
   printf("What type of dataset would you like to sort?\n");
   printf("A = random\n");
   printf("B = half ascending, half descending\n");
   printf("C = reverse sorted\n");
   printf("D = sorted array\n");
   printf("E = Half sorted\n");

   printf("Pick A, B C D or E\n");
   //asking user for input
   char ans[1];
   scanf("%s", ans);
   //generating the dataset the requested
   num_gen(number_array, x);
   if (ans[0] == 'A' || ans[0] == 'a'){
     printf("You picked A.\n");
   }
   else if (ans[0] == 'B' || ans[0] == 'b'){
     printf("You picked B.\n");
     half_and_half(x, number_array);

   }
   else if (ans[0] == 'C' || ans[0] == 'c'){
     printf("You picked C.\n");
     rev_RadixSort(number_array, x);
   }

   else if (ans[0] == 'D' || ans[0] == 'd'){
     printf("You picked D.\n");
     radix_sort(number_array, x);
   }
   else if (ans[0] == 'E' || ans[0] == 'e'){
     printf("You picked E.\n");
     half_radix_sort(number_array, x);
   }
   else {
     printf("Incorrect letter entered. Try again.\n");
     return 0;
   }
   //letting the user pick what sorting algorithim to use
   char ans2[3];
   printf("What sorting algorithim would you like to use?\n");
   printf("Type ss for selection sort\n");
   printf("Type rs for radix sort\n");
   printf("Type qs for quick sort\n");
   
   scanf("%s", ans2);

   //implementing the sorting algorithim and timing it
   if (ans2[0] == 's' || ans2[0] == 'S'){
     double time_spent = 0.0;
     clock_t begin = clock();
     selection_sort(x, number_array);

     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
     printf("Time elpased is %f seconds\n", time_spent);
   }
   
   else if (ans2[0] == 'r' || ans2[0] == 'R'){
     double time_spent = 0.0;
     clock_t begin = clock();
     radix_sort(number_array, x);
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
     printf("Time elpased is %f seconds\n", time_spent);
   }
   else if (ans2[0] == 'q' || ans2[0] == 'Q'){
     double time_spent = 0.0;
     clock_t begin = clock();
     quick_sort(number_array, 0, x - 1);
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
     printf("Time elpased is %f seconds\n", time_spent);
   }
   //freeing the memory allocated to the array
   free(number_array);
   return 0;
}

