#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m) : word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
    return words;
}

void Dictionary::addWord(WordMean wm) {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
bool WordMean::operator<(const WordMean &wm2) const {
    if (this->word < wm2.word)
        return true;
    return false;
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
void Dictionary::readFile(ifstream &f) {
    string line1, line2;
    while (getline(f, line1)) {
        if (getline(f, line2)) {
            WordMean w = WordMean(line1, line2);
            this->words.insert(w);
        }
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
bool Dictionary::update(string w1, string m1) {
    WordMean newWm = WordMean(w1, m1);

    set<WordMean>::iterator it = words.find(newWm);
    if (it != words.end()) {
        words.erase(it);
        words.insert(newWm);
        return true;
    }
    words.insert(newWm);
    return false;
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
string Dictionary::consult(string w1, WordMean &previous, WordMean &next) const {
    WordMean w1m = WordMean(w1, "");
    set<WordMean>::iterator it = words.lower_bound(w1m);

    if (it->getWord() == w1)
        return it->getMeaning();

    if (it != words.begin() && it != words.end()) {
        next = *it;
        previous = *--it;
    }
    if (it == words.end()) {
        previous = *--it;
    }
    if (it == words.begin()) {
        next = *++it;
    }

    return "word not found";
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
void Dictionary::print() const {
    for (const WordMean &w: words) {
        cout << w.getWord() << endl << w.getMeaning() << endl;
    }
}
