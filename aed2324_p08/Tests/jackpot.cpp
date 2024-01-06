#include "jackpot.h"


Bet::Bet(vector<int> ns, string p) : numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot() {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
void Jackpot::addBet(const Bet &b) {
    bets.insert(b);
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
unsigned Jackpot::betsInNumber(unsigned num) const {
    unsigned count = 0;

    for (const Bet &it1: bets) {
        for (const int &it2: it1.getNumbers()) {
            if (it2 == num)
                count++;
        }
    }

    return count;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
vector<string> Jackpot::drawnBets(vector<int> draw) const {
    vector<string> res;

    for (const Bet & curr_bet : bets) {
        unsigned count = 0;
        for (const int &curr_num : curr_bet.getNumbers()) {
            if (find(draw.begin(), draw.end(), curr_num) != draw.end())
                count++;
        }
        if (count > 3)
            res.push_back(curr_bet.getPlayer());
    }

    return res;
}
