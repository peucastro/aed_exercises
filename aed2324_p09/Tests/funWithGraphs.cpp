#include "funWithGraphs.h"


//=============================================================================
// Exercise 2: Vertex degrees
//=============================================================================
// Subexercise 2.1: outDegree
//=============================================================================
int FunWithGraphs::outDegree(const Graph<int> g, const int &v) {
    Vertex<int> *vertexTarget = g.findVertex(v);

    if (vertexTarget == NULL)
        return -1;

    return vertexTarget->getAdj().size();
}


//=============================================================================
// Subexercise 2.2: inDegree
//=============================================================================
int FunWithGraphs::inDegree(const Graph<int> g, const int &v) {
    Vertex<int> *vertexTarget = g.findVertex(v);

    if (vertexTarget == NULL)
        return -1;

    int res = 0;
    for (Vertex<int> *const &currVertex: g.getVertexSet()) {
        for (Edge<int> const &currEdge: currVertex->getAdj()) {
            if (currEdge.getDest() == vertexTarget)
                res++;
        }
    }

    return res;
}

//=============================================================================
// Subexercise 2.3: weightedOutDegree
//=============================================================================
int FunWithGraphs::weightedOutDegree(const Graph<int> g, const int &v) {
    Vertex<int> *vertexTarget = g.findVertex(v);

    if (vertexTarget == NULL)
        return -1;

    int res = 0;
    for (const Edge<int> &currEdge : vertexTarget->getAdj()) {
        res += currEdge.getWeight();
    }

    return res;
}
