//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0341_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0341_H

#include <vector>
#include <stack>
#include <algorithm>
#include "nestedinteger.h"

using namespace std;

class NestedIterator {
    // 巧妙做法：用栈模拟DFS过程，保存当前位置和末尾位置（迭代器变量）
public:
    NestedIterator(vector<NestedInteger> &nested_list) {
        stk.emplace(nested_list.begin(), nested_list.end());
    }

    int next() {
        // 由于保证调用 next 之前会调用 hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
        auto &p = stk.top();
        auto ans = p.first->getInteger();
        p.first++;
        return ans;
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto &p = stk.top();
            if (p.first == p.second) { // 遍历到当前列表末尾，出栈
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            // 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
            auto &lst = p.first->getList();
            stk.emplace(lst.begin(), lst.end());
            p.first++;
        }
        return false;
    }

private:
    // pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0341_H
