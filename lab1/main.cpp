#include <iostream>
#include <chrono>

#include "fibonacci.h"

#define FIB_VALUE 20        // CHANGE THIS VALUE

int main() {

    // RUNNING RECURSIVE
    std::cout << "Running recursive fibbonaci for " << FIB_VALUE<<"\nTime complexity of this algorithm is exponent (T(n) with n > 2), because of multiple repeating operations on each recursion step\n >> ";

    auto stopwatch = std::chrono::high_resolution_clock::now();
    double dt = fib_recursive(FIB_VALUE);

    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
            stopwatch).count() << "mks\n >> Result: " << dt << "\n\n";

    // ---------------
    // RUNNING DYNAMIC
    std::cout << "Running dynamic fibbonaci for " << FIB_VALUE<<"\nTime complexity of this algorithm is linear O(n)\n >> ";

    stopwatch = std::chrono::high_resolution_clock::now();
    dt = fib_dynamic(FIB_VALUE);

    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
            stopwatch).count() << "mks\n >> Result: " << dt << "\n\n";
    // ----------------------
    // RUNNING APPROX FORMULA
    std::cout << "Running approximative formula fibbonaci for " << FIB_VALUE<<"\nTime complexity of this algorithm is O(1), because no loops, it's just a formula\n >> ";

    stopwatch = std::chrono::high_resolution_clock::now();
    dt = fib_approx_binet(FIB_VALUE);

    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
            stopwatch).count() << "mks\n >> Result: " << dt << "\n\n";

    // -----------------------
    // RUNNING APPROX ROUNDING
    std::cout << "Running approximative rounding fibbonaci for " << FIB_VALUE<<"\nTime complexity of this algorithm is O(1), because no loops, it's just a formula\n >> ";

    stopwatch = std::chrono::high_resolution_clock::now();
    dt = fib_approx_round(FIB_VALUE);

    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
            stopwatch).count() << "mks\n >> Result: " << dt << "\n\n";


    return 0;
}
