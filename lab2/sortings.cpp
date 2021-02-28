//
// Created by foxfurry on 2/28/21.
//

#include "sortings.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Shell sort

void shell_sort(int *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Heap sort

void make_heap(int *arr, int n, int i) {
    int largest = i;
    int low = 2 * i + 1;
    int high = 2 * i + 2;

    if (low < n && arr[low] > arr[largest])
        largest = low;

    if (high < n && arr[high] > arr[largest])
        largest = high;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        make_heap(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)make_heap(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        make_heap(arr, i, 0);
    }
}

// Merge sort

void merge(int arr[], int low, int m, int high) {
    int n1 = m - low + 1;
    int n2 = high - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)R[j] = arr[m + 1 + j];

    int i = 0, j = 0, s = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[s] = L[i];
            i++;
        } else {
            arr[s] = R[j];
            j++;
        }
        s++;
    }

    while (i < n1) {
        arr[s] = L[i];
        i++;
        s++;
    }

    while (j < n2) {
        arr[s] = R[j];
        j++;
        s++;
    }
}

void merge_sort(int *arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int m = low + (high - low) / 2;
    merge_sort(arr, low, m);
    merge_sort(arr, m + 1, high);
    merge(arr, low, m, high);
}


// Quick sort

int quick_sort_partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = quick_sort_partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}