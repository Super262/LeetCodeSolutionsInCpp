//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0155_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0155_H

#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> storage;
    stack<int> minimal;

public:
    MinStack() {

    }

    void push(const int &val) {
        storage.emplace(val);
        if (minimal.empty()) {
            minimal.emplace(val);
        } else {
            minimal.emplace(min(val, minimal.top()));
        }
    }

    void pop() {
        storage.pop();
        minimal.pop();
    }

    int top() {
        return storage.top();
    }

    int getMin() {
        return minimal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0155_H
