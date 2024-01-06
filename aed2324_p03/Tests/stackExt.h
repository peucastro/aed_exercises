#include <iostream>
#include <stack>

using namespace std;

template<class T>
class StackExt {
    stack<T> values;
    stack<T> minimums;
public:
    StackExt() {};

    bool empty() const;

    T &top();

    void pop();

    void push(const T &val);

    T &findMin();
};

//=============================================================================
// Exercise 3: StackExt class
//=============================================================================
template<class T>
bool StackExt<T>::empty() const {
    return values.empty();
}

template<class T>
T &StackExt<T>::top() {
    if (!values.empty())
        return values.top();
    else
        throw runtime_error("Stack is empty");
}

template<class T>
void StackExt<T>::pop() {
    if (!values.empty()) {
        if (minimums.top() == values.top()) {
            minimums.pop();
        }
        values.pop();
    }
}

template<class T>
void StackExt<T>::push(const T &val) {
    values.push(val);
    if (minimums.empty() || val <= minimums.top()) {
        minimums.push(val);
    }
}

template<class T>
T &StackExt<T>::findMin() {
    return minimums.top();
}
