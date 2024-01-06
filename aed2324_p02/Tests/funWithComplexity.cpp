#include "funWithComplexity.h"

//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================

int FunWithComplexity::river(const vector<int> &v, int k, int t) {
    int satisfactory_count = 0;
    int deeper_count = 0;

    for (int i = 0; i <= v.size() - k; i++) {
        for (int j = i; j < i + k; j++) {
            if (v.at(j) >= t) deeper_count++;
        }
        if (deeper_count >= (double) k / 2.0) satisfactory_count++;
        deeper_count = 0;
    }
    return satisfactory_count;
}

//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}