#include "funSortProblem.h"

FunSortProblem::FunSortProblem() {}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (values.size() < nc)
        return -1;

    vector<unsigned> values_sorted = vector<unsigned>(values.begin(), values.end());
    sort(values_sorted.begin(), values_sorted.end());

    unsigned minimum = 0;
    unsigned maximum = nc - 1;
    unsigned diff = values_sorted[maximum] - values_sorted[minimum];

    while (maximum < values.size()) {
        if (values_sorted[maximum] - values_sorted[minimum] < diff)
            diff = values_sorted[maximum] - values_sorted[minimum];
        minimum++;
        maximum++;
    }

    return diff;
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
//TODO
unsigned FunSortProblem::numInversions(vector<int> v) {
    return 0;
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}
