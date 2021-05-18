#include <iostream>
#include <chrono>
#include "Graph.h"

template<typename varT, typename... varArgs>
double execTime(varT def(varArgs...), varArgs... fun_args){
    auto stopwatch_start = std::chrono::high_resolution_clock::now();
    def(fun_args...);
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() -
            stopwatch_start).count();
}

void callMethodAsFuncPointer(Graph* pGraph, void(Graph::*pMethod)()){
    (pGraph->*pMethod)();
}

int main() {
    Graph g1,g2;

    printf("SMALL GRAPH\n");
    g1 = generateSmall(); g2 = Graph(g1);
    printf("KRUS: \t%f mcs\nPRIM: \t%f mcs\n",
           execTime(callMethodAsFuncPointer, &g1, &Graph::kruskal),
           execTime(callMethodAsFuncPointer, &g2, &Graph::prim));
    printf("MEDIUM GRAPH\n");
    g1 = generateMedium(); g2 = Graph(g1);
    printf("KRUS: \t%f mcs\nPRIM: \t%f mcs\n",
           execTime(callMethodAsFuncPointer, &g1, &Graph::kruskal),
           execTime(callMethodAsFuncPointer, &g2, &Graph::prim));
    printf("BIG SPARSE GRAPH\n");
    g1 = generateBigSparse(); g2 = Graph(g1);
    printf("KRUS: \t%f mcs\nPRIM: \t%f mcs\n",
           execTime(callMethodAsFuncPointer, &g1, &Graph::kruskal),
           execTime(callMethodAsFuncPointer, &g2, &Graph::prim));
    printf("BIG DENSE GRAPH\n");
    g1 = generateBigDense(); g2 = Graph(g1);
    printf("KRUS: \t%f mcs\nPRIM: \t%f mcs\n",
           execTime(callMethodAsFuncPointer, &g1, &Graph::kruskal),
           execTime(callMethodAsFuncPointer, &g2, &Graph::prim));
}
