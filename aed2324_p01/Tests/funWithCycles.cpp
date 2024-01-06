#include "funWithCycles.h"

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================

bool FunWithCycles::palindrome(const std::string &s) {
    for (int i = 0; i < s.length(); i++)
        if (s.at(i) != s.at(s.length() - i - 1))
            return false;
    return true;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================

bool FunWithCycles::palindromeSentence(const std::string &s) {
    string str;
    for (const char &i: s)
        if ((i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z'))
            str.push_back(tolower(i));
    return palindrome(str);
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================

int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n++;
    while (digitSum(n) != sum)
        n++;
    return n;
}

// This auxiliary function should return the sum of the digits of n
int FunWithCycles::digitSum(int n) {
    string str = to_string(n);
    int sum = 0;
    for (char i: str)
        sum += i - '0';
    return sum;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================

int FunWithCycles::winter(const vector<int> &v) {
    vector<int> diff;
    for (int i = 0; i < v.size() - 1; i++)
        diff.push_back(v.at(i + 1) - v.at(i));

    int max = 0;
    int aux = 0;
    for (int j: diff) {
        if (j < 0) {
            aux++;
            if (aux > max)
                max = aux;
            continue;
        }
        aux = 0;
    }
    return max;
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
int FunWithCycles::count(const vector<int> &v, int n) {
    int occ = 0;
    for (const int &i: v)
        if (i == n)
            occ++;
    return occ;
}

// b) hasDuplicates
bool FunWithCycles::hasDuplicates(const vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (v.at(i) == v.at(j))
                return true;
    return false;
}

// c) removeDuplicates
void FunWithCycles::removeDuplicates(vector<int> &v) {
    for (int i = 0; i < v.size() + 1; i++)
        for (int j = i + 1; j < v.size();) {
            if (v.at(i) == v.at(j))
                v.erase(v.begin() + j);
            else
                j++;
        }
}

// d) merge
vector<int> FunWithCycles::merge(const vector<int> &v1, const vector<int> &v2) {
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            ans.push_back(v1[i]);
            i++;
        } else if (v1[i] > v2[j]) {
            ans.push_back(v2[j]);
            j++;
        } else {
            ans.push_back(v1[i]);
            ans.push_back(v2[j]);
            i++;
            j++;
        }
    }

    while (i < v1.size()) {
        ans.push_back(v1[i]);
        i++;
    }

    while (j < v2.size()) {
        ans.push_back(v2[j]);
        j++;
    }

    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
bool FunWithCycles::isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

// b) factorize
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    int p = 2;

    while (n != 1) {
        if (n % p == 0) {
            n /= p;
            ans.push_back(p);
        } else {
            p++;
            while (!isPrime(p))
                p++;
        }
    }
    return ans;
}

// c) listPrimes
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;

    for (int i = 2; i <= n; i++)
        if (isPrime(i))
            ans.push_back(i);

    return ans;
}