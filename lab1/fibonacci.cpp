//
// Created by foxfurry on 03/02/2021.
//

#include "fibonacci.h"

double fib_recursive(int n){
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}


double fib_dynamic(int n){
    int fib_arr[n + 2];

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for(int i = 2; i <= n; i++){
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
    }
    return fib_arr[n];
}


double fib_approx_binet(int n){
    return (pow((double)GOLD_RATIO, n) - pow((double)BERNUOLLI_NUM, n)) / (double)sqrt(5);
}


int fib_approx_round(int n){
    return (int)(pow((double)GOLD_RATIO,n) / (GOLD_RATIO - BERNUOLLI_NUM));
}