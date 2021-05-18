//
// Created by foxfurry on 5/9/21.
//

#include <iostream>
#include "Graph.h"

void Graph::dijkstra(){

//    if(edgeMap.find(sink) == edgeMap.end()){
//        std::cout << "Sink key not found in map\n";
//        return -1;
//    }else if(edgeMap.find(source) == edgeMap.end()){
//        std::cout << "Source key not found in map\n";
//        return -1;
//    }
    std::priority_queue<std::pair<int,int>,     // type
            std::vector<std::pair<int,int>>,    // container
                    std::greater<>> visited;    // comparator + name
    std::vector<int> distance(edgeMap.size(), INT32_MAX);
    distance[0] = 0;

    visited.push({0, 0});

    for(int i; !visited.empty(); ){
        i = visited.top().first;
        visited.pop();
        for(auto neighbor: edgeMap[i]){
            if ( distance[neighbor.first] > distance[i] + neighbor.second){
                distance[neighbor.first] = distance[i] + neighbor.second;
                visited.push({neighbor.first, distance[neighbor.first]});
            }
        } // forNeighbor
    } // forVisited

//    for(int i = 0; i < distance.size(); i++){
//        std::cout << i << " - " << distance[i] << '\n';
//    }
}

void Graph::floyd_warshall(){
    int edgeCount = edgeMap.size();
    std::vector<std::vector<int>> distanceMatrix(edgeCount, std::vector<int>(edgeCount, INT32_MAX));

    for(int i = 0; i < edgeCount; i++){
        for(auto value: edgeMap[i]){
            distanceMatrix[i][value.first] = value.second;
        }
        distanceMatrix[i][i] = 0;
    }

    for(int k = 0; k < edgeCount; k++){
        for(int i = 0; i < edgeCount; i++){
            for(int j = 0; j < edgeCount; j++){
                if (distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j]
                    && (distanceMatrix[k][j] != INT32_MAX
                        && distanceMatrix[i][k] != INT32_MAX)){
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                }
            }
        }
    }

//    for(int i = 0; i < edgeCount; i++){
//        for(int j = 0; j < edgeCount; j++){
//            if(distanceMatrix[i][j] == INT32_MAX){
//                std::cout << "INF";
//            }
//            else
//                std::cout << distanceMatrix[i][j];
//            std::cout << '\t';
//        }
//        std::cout << '\n';
//    }
}

Graph generateGraph(int vertices, int edges, bool _directed){
    int initialV = vertices;
    if(vertices<=1 || edges<=0){
        return Graph(_directed);
    }
    std::random_device rd;
    std::default_random_engine rand_engine(rd());

    Graph result(_directed);
    int lastVertice = 2;
    vertices -= lastVertice;
    edges--;
    result.addEdge(0, 1, RAND_WEIGHT(rand_engine));

    while(true){
        if(result.getEdges().size() >= initialV*(initialV-1)/2){
            break;
        }
        if(vertices > 0 && edges > 0){
            int sink = RAND_RANGE(rand_engine, 0, lastVertice-1),
                    weight = RAND_WEIGHT(rand_engine);

            result.addEdge(lastVertice,sink,weight);
            lastVertice++;
            vertices--; edges--;
        }
        else if(edges > 0){
            int source = 0, sink = 0, weight = RAND_WEIGHT(rand_engine);
            while(source == sink){
                source = RAND_RANGE(rand_engine, 0, lastVertice-1);
                sink = RAND_RANGE(rand_engine, 0, lastVertice-1);
            }
            result.addEdge(source, sink, weight);
            edges--;
        }
        else{
            break;
        }
    }
    return result;
}

Graph generateSmall(bool _directed){
    return generateGraph(SMALL, SMALL*DENSE, _directed);
}
Graph generateMedium(bool _directed){
    return generateGraph(MEDIUM, MEDIUM*DENSE, _directed);
}
Graph generateBigSparse(bool _directed){
    return generateGraph(BIG, BIG*SPARSE, _directed);
}
Graph generateBigDense(bool _directed){
    return generateGraph(BIG, BIG*DENSE, _directed);
}

