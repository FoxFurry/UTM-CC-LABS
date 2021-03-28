//
// Created by foxfurry on 3/28/21.
//

#ifndef CC_LABS_GRAPH_H
#define CC_LABS_GRAPH_H

#include <iostream>
#include <list>
#include <queue>

class Graph {
    int V;
    std::list <int> * adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V){
        this->V = V;
        adj = new std::list<int>[V];
    }

    void addEdge(int V, int w) {
        this->adj[V].push_back(w);
    }
    void DFS();
    void BFS();

};

#endif //CC_LABS_GRAPH_H