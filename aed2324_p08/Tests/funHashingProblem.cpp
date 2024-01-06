#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
vector<int> FunHashingProblem::findDuplicates(const vector<int> &values, int k) {
    vector<int> res;
    unordered_set<int> seen;

    for (size_t i = 0; i < values.size(); i++) {
        if (seen.size() > k - 1)
            seen.erase(seen.begin());

        unordered_set<int>::iterator it = seen.find(values[i]);
        if (it != seen.end())
            res.push_back(*it);
        seen.insert(values[i]);
    }

    return res;
}
