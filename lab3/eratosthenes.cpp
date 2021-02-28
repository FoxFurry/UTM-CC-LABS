//
// Created by foxfurry on 2/28/21.
//

#include "eratosthenes.h"
#include <cstring>
#include <cmath>
#include <iostream>

#define PRINT_PRIME false

void print_primes(bool *primes, int n) {
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            std::cout << i << '\n';
        }
    }
}

void eratosthenes_1(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    int i = 2, j;
    while (i <= n) {
        if (primes[i] == true) {
            j = 2 * i;
            while (j <= n) {
                primes[j] = false;
                j = j + i;
            }
        }
        i = i + 1;
    }
    if(PRINT_PRIME)print_primes(primes, n);
}

void eratosthenes_2(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    primes[1] = false;
    int i = 2, j;
    while (i <= n) {
        j = 2 * i;
        while (j <= n) {
            primes[j] = false;
            j = j + i;
        }
        i = i + 1;
    }
    if(PRINT_PRIME)print_primes(primes, n);
}

void eratosthenes_3(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    primes[1] = false;
    int i = 2, j;
    while (i<=n) {
        if (primes[i] == true) {
            j = i + 1;
            while (j <= n) {
                if (j % i == 0) {
                    primes[j] = false;
                }
                j = j + 1;
            }
        }
        i = i + 1;
    }
    if(PRINT_PRIME)print_primes(primes, n);
}

void eratosthenes_4(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    primes[1] = false;
    int i = 2, j;
    while (i <= n) {
        j = 2;
        while (j < i) {
            if (i % j == 0) {
                primes[i] = false;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    if(PRINT_PRIME)print_primes(primes, n);
}

void eratosthenes_5(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    primes[1] = false;
    int i = 2, j;
    while (i<=n){
        j=2;
        while (j<=sqrt(i)){
            if (i % j == 0) {
                primes[i] = false;
            }
            j++;
        }
        i++;
    }
    if(PRINT_PRIME)print_primes(primes, n);
}