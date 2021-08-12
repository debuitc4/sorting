#ifndef SORTING_H
#define SORTING_H

//quick sort prototypes
void quick_sort(int * nums, int low, int high) ;
void swap(int *a, int *b);
int partition(int nums[], int low, int high);

//selection sort prototypes
void selection_sort(int len, int *a);

//radix sort prototypes
void radix_sort(int * a, int len);
void count_sort(int a[], int len, int place);
int get_max(int a[], int n);

//reverse sort
void rev_RadixSort(int * a, int n);


//radix sort half sort array
void half_radix_sort(int * a, int len);
void half_count_sort(int a[], int len, int place);
int half_get_max(int a[], int n);

#endif
