//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0895_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0895_H

#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class FreqStack {
    // 类似"拉链法"，哈希表记录频率，用栈依次存储元素
public:
    FreqStack() {
        max_freq = 0;
    }

    void push(int val) {
        freq[val]++;
        f_stk[freq[val]].emplace(val);
        max_freq = max(freq[val], max_freq);
    }

    int pop() {
        auto ans = f_stk[max_freq].top();
        f_stk[max_freq].pop();
        if (f_stk[max_freq].empty()) {
            --max_freq;
        }
        freq[ans]--;
        return ans;
    }

private:
    int max_freq;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> f_stk;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0895_H
