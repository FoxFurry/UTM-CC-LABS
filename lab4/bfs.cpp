//
// Created by foxfurry on 3/28/21.
//

#include "graph.h"

void Graph::BFS(){
    std::queue <int> myQueue;
    bool * visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    if (visited[0] == false) {
        myQueue.push(0);
        visited[0] = true;
        while (!myQueue.empty()) {
            std::list<int>::iterator i;
            int node = myQueue.front();
            for (i = adj[node].begin(); i != adj[node].end(); i++)
                if (!visited[*i]) {
                    //std::cout << *i << '\n';
                    visited[*i] = true;
                    myQueue.push(*i);
                }
            myQueue.pop();
        }
    }
}