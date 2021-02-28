//
// Created by foxfurry on 2/28/21.
//

#ifndef CC_LABS_SORTINGS_H
#define CC_LABS_SORTINGS_H


void swap(int *a, int *b);      // Swap two integers (or chars if you are brave enough)


void shell_sort(int *arr, int n);

void make_heap(int *arr, int n, int i);
void heap_sort(int *arr, int n);

void merge(int arr[], int low, int m, int high);
void merge_sort(int *arr, int low, int high);

int quick_sort_partition (int *arr, int low, int high); // create a valid partition around pivot element
void quick_sort(int *arr, int low, int high);

#endif //CC_LABS_SORTINGS_H
