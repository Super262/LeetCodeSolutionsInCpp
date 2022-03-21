//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0232_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0232_H

#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() = default;

    void push(int x) {
        storage.emplace(x);
    }

    int pop() {
        while (!storage.empty()) {
            temp.emplace(storage.top());
            storage.pop();
        }
        auto t = temp.top();
        temp.pop();
        while (!temp.empty()) {
            storage.emplace(temp.top());
            temp.pop();
        }
        return t;
    }

    int peek() {
        while (!storage.empty()) {
            temp.emplace(storage.top());
            storage.pop();
        }
        auto t = temp.top();
        while (!temp.empty()) {
            storage.emplace(temp.top());
            temp.pop();
        }
        return t;
    }

    bool empty() {
        return storage.empty();
    }

private:
    stack<int> storage;
    stack<int> temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0232_H
