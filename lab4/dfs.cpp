//
// Created by foxfurry on 3/28/21.
//

#include "graph.h"

void Graph::DFSUtil(int v , bool visited[]) {
    visited[v] = true;
    //std::cout << v << " ";

    std::list<int>:: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            DFSUtil(i, visited);

}