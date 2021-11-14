//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0225_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0225_H

class MyStack {
public:
    /** Push element x onto stack. */
    void push(int x) {
        data2.emplace(x);
        while (!data1.empty()) {
            data2.emplace(data1.front());
            data1.pop();
        }
        swap(data2, data1);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = data1.front();
        data1.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return data1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data1.empty() && data2.empty();
    }

private:
    queue<int> data1, data2;
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
