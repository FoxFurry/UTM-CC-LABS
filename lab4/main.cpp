#include <iostream>
#include <chrono>
#include <random>
#include "graph.h"

template<typename varT, typename... varArgs>
double execTime(varT def(varArgs...), varArgs... fun_args){
    auto stopwatch_start = std::chrono::high_resolution_clock::now();
    def(fun_args...);
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
            stopwatch_start).count();
}

#define NODESIZE_LOW 1
#define NODESIZE_HIGH 100

#define NODEVAL_LOW 1

#define INT_DISTR(LOW, HIGH) std::uniform_int_distribution<int>{LOW, HIGH}(mersenne_engine)

void callMethodAsFuncPointer(Graph* pGraph, void(Graph::*pMethod)()){
    (pGraph->*pMethod)();
}

int main(){

    std::random_device rnd_device;
    std::mt19937 mersenne_engine {rnd_device()};

    int node_size = INT_DISTR(NODESIZE_LOW, NODESIZE_HIGH);

    Graph myGraph(node_size);

    for(int i = 0; i < node_size; i++){
        myGraph.addEdge(INT_DISTR(NODEVAL_LOW, node_size-1),INT_DISTR(NODEVAL_LOW, node_size-1));
    }

    std::cout << "Graph size: " << node_size << '\n';

    std::cout <<    "BFS Time: " << execTime(callMethodAsFuncPointer, &myGraph, &Graph::BFS) <<
                    " ms\nDFS Time: " << execTime(callMethodAsFuncPointer, &myGraph, &Graph::DFS) << " ms\n";


    return 0;
}