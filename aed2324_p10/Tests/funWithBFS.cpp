#include "funWithBFS.h"
#include <iostream>

//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.2: Nodes at distance k (BFS)
//=============================================================================
vector<Person> FunWithBFS::nodesAtDistanceBFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    queue<Vertex<Person> *> aux;

    for (Vertex<Person> *v: g->getVertexSet())
        v->setVisited(false);

    if (k == 0) {
        res.push_back(source);
        return res;
    }

    Vertex<Person> *source_vertex = g->findVertex(source);
    aux.push(source_vertex);
    source_vertex->setVisited(true);

    while (!aux.empty()) {
        size_t s = aux.size();
        for (size_t i = 0; i < s; i++) {
            Vertex<Person> *curr = aux.front();
            aux.pop();

            for (const Edge<Person> &e: curr->getAdj()) {
                Vertex<Person> *neighbor = e.getDest();
                if (!neighbor->isVisited()) {
                    neighbor->setVisited(true);
                    aux.push(neighbor);
                }
            }
        }

        if (k == 1) {
            while (!aux.empty()) {
                res.push_back(aux.front()->getInfo());
                aux.pop();
            }
            return res;
        }

        k--;
    }

    return res;
}


//=============================================================================
// Exercise 2.2: Max New Children
//=============================================================================
int FunWithBFS::maxNewChildren(const Graph<Person> *g, const Person &source, Person &info) {
    queue<Vertex<Person> *> aux;
    int maxChildrenCount = 0;

    for (Vertex<Person> *v: g->getVertexSet())
        v->setVisited(false);

    Vertex<Person> *source_vertex = g->findVertex(source);
    aux.push(source_vertex);
    source_vertex->setVisited(true);

    while (!aux.empty()) {
        int curr_count = 0;
        Vertex<Person> *curr = aux.front();
        aux.pop();

        for (const Edge<Person> &e: curr->getAdj()) {
            Vertex<Person> *neighbor = e.getDest();
            if (!neighbor->isVisited()) {
                neighbor->setVisited(true);
                aux.push(neighbor);
                curr_count++;
            }
        }

        if (curr_count > maxChildrenCount) {
            maxChildrenCount = curr_count;
            info = curr->getInfo();
        }
    }

    return maxChildrenCount;
}
