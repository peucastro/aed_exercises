#include "funWithSearch.h"


//=============================================================================
// Exercise 1: Elementary Search
//=============================================================================
// Subexercise 1.1: Linear Search
//=============================================================================
int FunWithSearch::searchLinear(const vector<int> &v, int key) {
    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] == key)
            return i;
    }
    return -1;
}

//=============================================================================
// Subexercise 1.2: Binary Search
//=============================================================================
int FunWithSearch::searchBinary(const vector<int> &v, int key) {
    int low = 0, high = (int) v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle; // key found at index middle
    }
    return -1; // key not found
}

//=============================================================================
// Exercise 2: Facing Sun
//=============================================================================
int FunWithSearch::facingSun(const vector<int> &values) {
    int count = 1;
    for (unsigned i = 1; i < values.size(); i++) {
        if (values[i] > values[i - 1])
            count++;
    }
    return count;
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
int FunWithSearch::squareR(int num) {
    int square = 2;
    int last_square = 2;

    for (int i = 0; i < num; i++) {
        if (square > last_square)
            return last_square;
        last_square = square;
        square *= square;
    }
}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================
// TODO
int FunWithSearch::minPages(const vector<int> &values, int numSt) {
    return 0;
}
