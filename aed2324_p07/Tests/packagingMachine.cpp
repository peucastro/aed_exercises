#include "packagingMachine.h"

PackagingMachine::PackagingMachine(int boxCap) : boxCapacity(boxCap) {}

unsigned PackagingMachine::numberOfBoxes() {
    return boxes.size();
}

unsigned PackagingMachine::addBox(Box &b1) {
    boxes.push(b1);
    return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
    return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
    return this->boxes;
}


//=============================================================================
// Exercise 1: Packaging
//=============================================================================
// Subexercise 1.1: Load Objects
//=============================================================================
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    unsigned ans = 0;
    vector<Object>::iterator it = objs.begin();

    while (it != objs.end()) {
        if (it->getWeight() <= this->boxCapacity) {
            ans++;
            this->objects.push(*it);
            it = objs.erase(it);
        } else {
            ++it;
        }
    }

    return ans;
}


//=============================================================================
// Subexercise 1.2: Search Box
//=============================================================================
Box PackagingMachine::searchBox(Object &obj) {
    queue<Box> aux;
    Box box;
    bool flag = false;

    while (!boxes.empty()) {
        if (boxes.top().getFree() >= obj.getWeight()) {
            flag = true;
            box = boxes.top();
            boxes.pop();
            break;

        } else {
            aux.push(boxes.top());
            boxes.pop();
        }
    }

    while (!aux.empty()) {
        boxes.push(aux.front());
        aux.pop();
    }

    return box;
}

//=============================================================================
// Subexercise 1.3: Pack Objects
//=============================================================================
unsigned PackagingMachine::packObjects() {
    HeapObj objs = getObjects();

    while (!objs.empty()) {
        Object obj = objs.top();
        Box bx = searchBox(obj);
        bx.addObject(obj);
        addBox(bx);
        objs.pop();
    }

    return boxes.size();
}


//=============================================================================
// Subexercise 1.4: Box with More Objects
//=============================================================================
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
    size_t max = 0;

    HeapBox boxes_copy = boxes;
    while (!boxes_copy.empty()) {
        Box top_box = boxes_copy.top();

        if (top_box.getSize() > max) {
            max = top_box.getSize();
            res = top_box.getObjects();
        }

        boxes_copy.pop();
    }

    return res;
}
