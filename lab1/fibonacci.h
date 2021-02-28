//
// Created by foxfurry on 03/02/2021.
//

#ifndef CC_LABS_FIBONACCI_H
#define CC_LABS_FIBONACCI_H

#include <cmath>

#define GOLD_RATIO 1.6180339887
#define BERNUOLLI_NUM -0.6180339887

double fib_recursive(int n);        // Just recursive
double fib_dynamic(int n);          // Dynamic method (memoization)
double fib_approx_binet(int n);     // Binet's formula
int fib_approx_round(int n);        // Rounding formula

#endif //CC_LABS_FIBONACCI_H
