//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0225_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0225_H

#include <queue>

using namespace std;

class MyStack {
public:
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp;
        temp.emplace(x);
        while (!data.empty()) {
            temp.emplace(data.front());
            data.pop();
        }
        data = temp;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto res = data.front();
        data.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }

private:
    queue<int> data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0225_H
