//
// Created by foxfurry on 5/9/21.
//

#ifndef LAB7_GRAPH_H
#define LAB7_GRAPH_H
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <map>
#include <random>

#define WL      1
#define WH      500

#define SMALL   50
#define MEDIUM  500
#define BIG     1000

#define SPARSE  1.0f
#define DENSE   5.0f

#define RAND_WEIGHT(engine) std::uniform_int_distribution<int>(WL, WH)(engine)
#define RAND_RANGE(engine,x,y) std::uniform_int_distribution<int>(x, y)(engine)

class Graph {
private:
    std::map<int, std::vector<std::pair<int,int>>> edgeMap;
    bool directed;
public:
    Graph(Graph const &copyG) : edgeMap(copyG.edgeMap), directed(copyG.directed){ }
    explicit Graph(bool _directed): directed(_directed){};
    ~Graph()= default;

    std::map<int, std::vector<std::pair<int,int>>> getEdges() const{ return edgeMap; }
    bool isDirected() const{ return directed; }

    void addEdge(int nodeA, int nodeB, int weight){
        edgeMap[nodeA].push_back({nodeB, weight});
        if(directed)edgeMap[nodeB].push_back({nodeA, weight});
    }

    void dijkstra();
    void floyd_warshall();
};

Graph generateGraph(int vertices, int edges, bool _directed);
Graph generateSmall(bool _directed);
Graph generateMedium(bool _directed);
Graph generateBigSparse(bool _directed);
Graph generateBigDense(bool _directed);

#endif //LAB7_GRAPH_H
