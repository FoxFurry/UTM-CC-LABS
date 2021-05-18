//
// Created by foxfurry on 5/4/21.
//

#include <iostream>
#include "Graph.h"


bool edgeComparator(Edge a, Edge b) {
    return a.weight < b.weight;
}

void Graph::kruskal() {
    std::vector<Graph> forest;
    Graph mst;

    std::stable_sort(edgeV.begin(), edgeV.end(), edgeComparator);

    for (auto edge: edgeV) {
        std::pair<int, int> parents = kruskalGetParent(edge, forest);

        if (parents.first == -1 && parents.second == -1) {
            Graph newG;
            newG.addEdge(edge);
            forest.push_back(newG);
        } else if (parents.first == -1) {
            forest[parents.second].addEdge(edge);
        } else if (parents.second == -1) {
            forest[parents.first].addEdge(edge);
        } else if (parents.first == parents.second) {
            continue;
        } else {
            kruskalMergeGraph(&forest, parents);
        }
        mst.addEdge(edge);
    }

    //printGraph(mst);
}
void Graph::kruskalMergeGraph(std::vector<Graph> *pForest, std::pair<int, int> idx) {
    for (auto edge: pForest->at(idx.second).edgeV) {
        pForest->at(idx.first).addEdge(edge);
    }
    pForest->erase(pForest->begin() + idx.second);
}
std::pair<int, int> Graph::kruskalGetParent(Edge targetEdge, std::vector<Graph> targetForest) {
    int source = -1, sink = -1;
    for (int i = 0; i < targetForest.size(); i++) {
        Graph currentGraph = targetForest[i];
        for (auto currentEdge: currentGraph.getEdges()) {
            if (currentEdge.source == targetEdge.source || currentEdge.sink == targetEdge.source)
                source = i;
            if (currentEdge.source == targetEdge.sink || currentEdge.sink == targetEdge.sink)
                sink = i;
        }

        if (source != -1 && sink != -1) {
            break;
        }
    }
    return {source, sink};
}

void Graph::prim() {
    Graph mst;

    std::priority_queue<Edge, std::vector<Edge>, compareEdges> edgeQueue;
    std::multiset<int> isSet;

    int initialVertex = 0;
    primPushEdgesToQueue(&edgeQueue, initialVertex);
    while (!edgeQueue.empty()) {
        Edge current = edgeQueue.top();
        edgeQueue.pop();

        if (isSet.find(current.sink) == isSet.end() || isSet.find(current.source) == isSet.end()) {
            mst.addEdge(current);

            isSet.insert(current.source);
            isSet.insert(current.sink);

            primPushEdgesToQueue(&edgeQueue, current.source);
            primPushEdgesToQueue(&edgeQueue, current.sink);
        }
    }
    //printGraph(mst);
}
void Graph::primPushEdgesToQueue(std::priority_queue<Edge, std::vector<Edge>, compareEdges> *_edgeQueue, int vertex) {
    for (auto data: edgeV) {
        if (data.source == vertex || data.sink == vertex) {
            _edgeQueue->push(data);
        }
    }
}

Graph generateGraph(int vertices, int edges){
    int initialV = vertices;
    if(vertices<=1 || edges<=0){
        return Graph();
    }
    std::random_device rd;
    std::default_random_engine rand_engine(rd());

    Graph result;
    int lastVertice = 2;
    vertices -= lastVertice;
    edges--;
    result.addEdge({0, 1, RAND_WEIGHT(rand_engine)});

    while(true){
        if(result.getEdges().size() >= initialV*(initialV-1)/2){
            break;
        }
        if(vertices > 0 && edges > 0){
            int sink = RAND_RANGE(rand_engine, 0, lastVertice-1),
                weight = RAND_WEIGHT(rand_engine);

            result.addEdge({lastVertice,sink,weight});
            lastVertice++;
            vertices--; edges--;
        }
        else if(edges > 0){
            int source = 0, sink = 0, weight = RAND_WEIGHT(rand_engine);
            while(source == sink){
                source = RAND_RANGE(rand_engine, 0, lastVertice-1);
                sink = RAND_RANGE(rand_engine, 0, lastVertice-1);
            }
            result.addEdge({source, sink, weight});
            edges--;
        }
        else{
            break;
        }
    }
    return result;
}

Graph generateSmall(){
    return generateGraph(SMALL, SMALL*DENSE);
}
Graph generateMedium(){
    return generateGraph(MEDIUM, MEDIUM*DENSE);
}
Graph generateBigSparse(){
    return generateGraph(BIG, BIG*SPARSE);
}
Graph generateBigDense(){
    return generateGraph(BIG, BIG*DENSE);
}

void printGraph(Graph gr){
    for(auto edge: gr.getEdges()){
        printf("%d %d %d\n", edge.source, edge.sink, edge.weight);
    }
}