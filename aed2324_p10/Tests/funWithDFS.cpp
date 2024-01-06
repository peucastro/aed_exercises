#include "funWithDFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res) {
    v->setVisited(true);

    if (k == 0) {
        res.push_back(v->getInfo());
        return;
    }

    for (const Edge<Person> &edge: v->getAdj()) {
        Vertex<Person> *neighbor = edge.getDest();

        if (!neighbor->isVisited()) {
            nodesAtDistanceDFSVisit(g, neighbor, k - 1, res);
        }
    }

}

vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;

    Vertex<Person> *source_person = g->findVertex(source);

    for (Vertex<Person> *p: g->getVertexSet())
        p->setVisited(false);

    nodesAtDistanceDFSVisit(g, source_person, k, res);

    return res;
}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
bool dfsIsDAG(Vertex<int> *v) {
    v->setProcessing(true);
    v->setVisited(true);

    for (const Edge<int> &e: v->getAdj()) {
        Vertex<int> *w = e.getDest();

        if (w->isProcessing())
            return false;
        else if (!w->isVisited()) {
            bool flag = dfsIsDAG(w);
            if (!flag)
                return false;
        }
    }

    v->setProcessing(false);
    return true;
}

bool FunWithDFS::isDAG(Graph<int> g) {
    for (Vertex<int> *v: g.getVertexSet()) {
        v->setVisited(false);
        v->setProcessing(false);
    }

    for (Vertex<int> *v: g.getVertexSet()) {
        if (!v->isVisited()) {
            bool flag = dfsIsDAG(v);
            if (!flag)
                return false;
        }
    }

    return true;
}


