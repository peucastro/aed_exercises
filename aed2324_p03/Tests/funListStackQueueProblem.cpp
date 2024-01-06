#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;

    for (list<int>::iterator it = values.begin(); it != values.end();) {
        if (*it > x) {
            l1.push_back(*it);
            it = values.erase(it);
        } else
            it++;
    }
    return l1;
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
list<pair<int, int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int, int>> values) {
    list<pair<int, int>> res;
    values.sort([](pair<int, int> pair1, pair<int, int> pair2) -> bool { return pair1.first < pair2.first; });

    pair<int, int> current = values.front();

    for (const pair<int, int> &interval: values) {
        if (interval.first <= current.second) {
            current.second = max(current.second, interval.second);
        } else {
            res.push_back(current);
            current = interval;
        }
    }
    res.push_back(current);

    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> q;
    q.push("1");

    while (n-- > 0) {
        string binary = q.front();
        q.pop();
        res.push_back(binary);

        q.push(binary + "0");
        q.push(binary + "1");
    }

    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
vector<int> FunListStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    stack<pair<int, int>> stk;

    for (int &i: prices) {
        int span = 1;
        while (!stk.empty() && stk.top().first <= i) {
            span += stk.top().second;
            stk.pop();
        }

        stk.push({i, span});
        res.push_back(span);
    }

    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
