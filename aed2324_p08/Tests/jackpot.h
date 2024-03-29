#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class Bet {
    vector<int> numbers;
    string player;
public:
    Bet(vector<int> ns, string p);

    vector<int> getNumbers() const;

    string getPlayer() const;
};

//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
struct betHash {
    // Hash function
    int operator()(const Bet &b) const {
        int betHash = 0;

        for (vector<int>::const_iterator it = b.getNumbers().begin(); it != b.getNumbers().end(); it++) {
            betHash = 7 * betHash + *it;
        }

        return betHash;
    }

    // Equality function
    bool operator()(const Bet &b1, const Bet &b2) const {
        return b1.getNumbers() == b2.getNumbers();
    }
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Jackpot {
    tabHBet bets;
public:
    Jackpot();

    void addBet(const Bet &ap);

    unsigned betsInNumber(unsigned num) const;

    vector<string> drawnBets(vector<int> draw) const;

    unsigned getNumBets() const;
};

#endif 
