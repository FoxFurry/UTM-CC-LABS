#include <iostream>
#include <chrono>
#include <random>

#include "eratosthenes.h"

#define N_RANGE_LOW 1000
#define N_RANGE_HIGH 10000

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

    int n_val = std::uniform_int_distribution<int>{N_RANGE_LOW, N_RANGE_HIGH}(mersenne_engine);

    std::cout << "Prime range: " << n_val << '\n';
    for(int i = 0; i < 5; i++){
        void (*fp)(int);
        switch (i) {
            case 0: fp = eratosthenes_1; break;
            case 1: fp = eratosthenes_2; break;
            case 2: fp = eratosthenes_3; break;
            case 3: fp = eratosthenes_4; break;
            case 4: fp = eratosthenes_5; break;
            default: std::cout << "Wrong range\n";
        }

        std::cout << "Eratosthenes algorithm №" << i+1 << ": " << execTime(fp, n_val) << " ms\n";
    }

    return 0;
}


