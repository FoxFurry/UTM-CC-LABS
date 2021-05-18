//
// Created by foxfurry on 5/4/21.
//

#ifndef LAB6_GRAPH_H
#define LAB6_GRAPH_H

#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <random>

#define WL 1
#define WH 500

#define SMALL 50
#define MEDIUM 500
#define BIG 1000

#define SPARSE  1.0f
#define DENSE   5.0f

#define RAND_WEIGHT(engine) std::uniform_int_distribution<int>(WL, WH)(engine)
#define RAND_RANGE(engine,x,y) std::uniform_int_distribution<int>(x, y)(engine)



struct Edge{
    int source,
        sink,
        weight;
};

bool edgeComparator(Edge a, Edge b);
struct compareEdges{
    bool operator()(Edge const& e1, Edge const& e2){
        return e1.weight > e2.weight;
    }
};

class Graph {
private:
    std::vector<Edge> edgeV;

    static std::pair<int,int> kruskalGetParent(Edge targetEdge, std::vector<Graph> targetForest);
    static void kruskalMergeGraph(std::vector<Graph> *pForest, std::pair<int,int> idx);

    void primPushEdgesToQueue(std::priority_queue<Edge, std::vector<Edge>, compareEdges> *_edgeQueue, int vertex);
public:
    Graph()= default;
    ~Graph()= default;
    Graph(Graph const &copyG){
        edgeV = copyG.edgeV;
    }

    std::vector<Edge> getEdges(){ return edgeV; }
    void addEdge(Edge edge){
        edgeV.push_back(edge);
    }

    void kruskal();
    void prim();

};


Graph generateGraph(int vertices, int edges);
Graph generateSmall();
Graph generateMedium();
Graph generateBigSparse();
Graph generateBigDense();

void printGraph(Graph gr);

#endif //LAB6_GRAPH_H
