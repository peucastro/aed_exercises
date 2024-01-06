#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
pair<int, int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    set<int> bst;

    for (const int &value: values) {
        int diff = sum - value;

        set<int>::iterator it = bst.find(diff);
        if (it != bst.end()) {
            return make_pair(*it, value);
        }

        bst.insert(value);
    }
    return make_pair(0, 0);
}
