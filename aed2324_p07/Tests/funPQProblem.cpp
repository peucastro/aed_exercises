#include "funPQProblem.h"

FunPQProblem::FunPQProblem() {}


//=============================================================================
// Exercise 2: Minimum Cost
//=============================================================================
int FunPQProblem::minCost(const vector<int> &ropes) {
    int ans = 0;
    priority_queue<int, std::vector<int>, greater<int>> HeapRopes;

    for (const int &r: ropes)
        HeapRopes.push(r);

    while (!HeapRopes.empty()) {
        int top1 = HeapRopes.top();
        HeapRopes.pop();

        if (HeapRopes.empty()) {
            break;
        } else {
            int top2 = HeapRopes.top();
            HeapRopes.pop();
            HeapRopes.push(top1 + top2);
            ans += top1 + top2;
        }
    }

    return ans;
}
