#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>
#include "sortings.h"

#define MIN_GEN_SIZE 1000
#define MAX_GEN_SIZE 10000

#define MIN_GEN_VAL 10
#define MAX_GEN_VAL 1000

#define SIZE_DISTRIBUTION std::uniform_int_distribution<int>{MIN_GEN_SIZE, MAX_GEN_SIZE}(mersenne_engine)
#define VALUE_DISTRIBUTION std::uniform_int_distribution<int>{MIN_GEN_VAL, MAX_GEN_VAL}(mersenne_engine)
#define COPY_ARRAY memcpy(arr_cp, arr, arr_size*sizeof(int))

template<typename varT, typename... varArgs>
double execTime(varT def(varArgs...), varArgs... fun_args){
    auto stopwatch_start = std::chrono::high_resolution_clock::now();
    def(fun_args...);
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
                    stopwatch_start).count();
}

int main() {
    std::random_device rnd_device;
    std::mt19937 mersenne_engine {rnd_device()};

    int arr_size = SIZE_DISTRIBUTION;
    int *arr = new int[arr_size];

    for(int i = 0; i < arr_size; i++){
        arr[i] = VALUE_DISTRIBUTION;
    }

    int *arr_cp = new int[arr_size];
    std::cout << "array soze: " << arr_size << "\n\n";

    COPY_ARRAY;
    std::cout << "quick sort: " << execTime(quick_sort, arr_cp,0, arr_size-1) << " ms\n";
    COPY_ARRAY;
    std::cout << "merge sort: " << execTime(merge_sort, arr_cp,0, arr_size-1) << " ms\n";
    COPY_ARRAY;
    std::cout << "heap sort: " << execTime(heap_sort, arr_cp, arr_size-1) << " ms\n";
    COPY_ARRAY;
    std::cout << "shell sort: " << execTime(shell_sort, arr_cp, arr_size-1) << " ms\n";

    free(arr);
    free(arr_cp);
    return 0;
}
