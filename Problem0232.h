//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0232_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0232_H

#include <stack>

using namespace std;

class MyQueue {
    // 引入临时栈，实现反序操作
public:
    MyQueue() = default;

    void push(int x) {
        stack<int> temp;
        while (!data.empty()) {
            temp.emplace(data.top());
            data.pop();
        }
        data.emplace(x);
        while (!temp.empty()) {
            data.emplace(temp.top());
            temp.pop();
        }
    }

    int pop() {
        auto ans = data.top();
        data.pop();
        return ans;
    }

    int peek() {
        return data.top();
    }

    bool empty() {
        return data.empty();
    }

private:
    stack<int> data;
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
