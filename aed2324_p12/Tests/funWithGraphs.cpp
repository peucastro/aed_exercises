#include "funWithGraphs.h"

//=============================================================================
// Exercise 2.1: Connected Components
//=============================================================================
void dfsVisit(Vertex<int> *v) {
    v->setVisited(true);

    for (const Edge<int> &edge: v->getAdj()) {
        Vertex<int> *neighbor = edge.getDest();

        if (!neighbor->isVisited())
            dfsVisit(neighbor);
    }
}

int funWithGraphs::connectedComponents(Graph<int> *g) {
    int count = 0;

    for (Vertex<int> *v: g->getVertexSet()) {
        v->setVisited(false);
    }

    for (Vertex<int> *v: g->getVertexSet()) {
        if (!v->isVisited()) {
            count++;
            dfsVisit(v);
        }
    }

    return count;
}


//=============================================================================
// Exercise 2.2: Giant Component
//=============================================================================
int dfsGC(Vertex<int> *v) {
    int vtxCount = 1;
    v->setVisited(true);

    for (const Edge<int> &edge: v->getAdj()) {
        Vertex<int> *neighbor = edge.getDest();

        if (!neighbor->isVisited()) {
            vtxCount += dfsGC(neighbor);
        }
    }

    return vtxCount;
}

int funWithGraphs::giantComponent(Graph<int> *g) {
    int maxCount = 0;

    for (Vertex<int> *v: g->getVertexSet()) {
        v->setVisited(false);
    }

    for (Vertex<int> *v: g->getVertexSet()) {
        if (!v->isVisited()) {
            int currCount = dfsGC(v);
            if (currCount > maxCount)
                maxCount = currCount;
        }
    }

    return maxCount;
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i) {
    v->setVisited(true);
    v->setNum(i);
    v->setLow(i);
    i++;
    s.push(v->getInfo());

    for (const Edge<int> &edge: v->getAdj()) {
        Vertex<int> *neighbor = edge.getDest();

        if (!neighbor->isVisited()) {
            dfs_scc(g, neighbor, s, l, i);
            v->setLow(min(v->getLow(), neighbor->getLow()));
        }

        bool flag = false;
        stack<int> aux_s = s;
        while (!aux_s.empty()) {
            if (aux_s.top() == neighbor->getInfo()) {
                flag = true;
                break;
            } else {
                aux_s.pop();
            }
        }

        if (flag)
            v->setLow(min(v->getLow(), neighbor->getNum()));
    }


    if (v->getNum() == v->getLow()) {
        list<int> new_scc;

        int w;
        do {
            w = s.top();
            s.pop();
            new_scc.push_back(w);
        } while (w != v->getInfo());

        l.push_back(new_scc);
    }
}

list<list<int>> funWithGraphs::scc(Graph<int> *g) {
    list<list<int>> res;
    int index = 1;

    for (Vertex<int> *v: g->getVertexSet())
        v->setVisited(false);

    for (Vertex<int> *v: g->getVertexSet()) {
        if (v->getNum() == 0) {
            stack<int> s = {};
            dfs_scc(g, v, s, res, index);
        }
    }

    return res;
}


//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &l, int &i) {
    v->setNum(i);
    v->setLow(i);
    i++;
    int children = 0;
    s.push(v->getInfo());

    for (const Edge<int> &e: v->getAdj()) {
        Vertex<int> *w = e.getDest();

        if (w->getNum() == 0) {
            children++;
            dfs_art(g, w, s, l, i);
            v->setLow(min(v->getLow(), w->getLow()));

            if (v->getInfo() != 1 && w->getLow() >= v->getNum())
                l.insert(v->getInfo());

        } else if (w->getNum() > 0)
            v->setLow(min(v->getLow(), w->getNum()));
    }

    s.pop();
    if (v->getInfo() == 1 && children > 1)
        l.insert(v->getInfo());
}

unordered_set<int> funWithGraphs::articulationPoints(Graph<int> *g) {
    unordered_set<int> res;
    stack<int> s;
    int i = 0;

    for (Vertex<int> *v: g->getVertexSet())
        v->setNum(i);

    i++;
    for (Vertex<int> *v: g->getVertexSet())
        if (v->getNum() == 0)
            dfs_art(g, v, s, res, i);

    return res;
}
