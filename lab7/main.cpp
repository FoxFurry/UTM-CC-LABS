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

    Graph dijkstra = generateSmall(false);

    printf("Dijkstra small graph: %f mcs\n", execTime(callMethodAsFuncPointer, &dijkstra, &Graph::dijkstra));
    dijkstra = generateMedium(false);
    printf("Dijkstra medium graph: %f mcs\n", execTime(callMethodAsFuncPointer, &dijkstra, &Graph::dijkstra));
    dijkstra = generateBigSparse(false);
    printf("Dijkstra big sparse graph: %f mcs\n", execTime(callMethodAsFuncPointer, &dijkstra, &Graph::dijkstra));
    dijkstra = generateBigDense(false);
    printf("Dijkstra big dense graph: %f mcs\n\n", execTime(callMethodAsFuncPointer, &dijkstra, &Graph::dijkstra));


    Graph floyd = generateSmall(true);
    printf("Floyd small graph: %f mcs\n", execTime(callMethodAsFuncPointer, &floyd, &Graph::floyd_warshall));
    floyd = generateMedium(true);
    printf("Floyd medium graph: %f mcs\n", execTime(callMethodAsFuncPointer, &floyd, &Graph::floyd_warshall));
    //floyd = generateBigSparse(true);
    //printf("Floyd big sparse graph: %f mcs\n", execTime(callMethodAsFuncPointer, &floyd, &Graph::floyd_warshall));
    //floyd = generateBigDense(true);
    //printf("Floyd big dense graph: %f mcs\n", execTime(callMethodAsFuncPointer, &floyd, &Graph::floyd_warshall));

}
