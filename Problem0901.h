//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0901_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0901_H

#include <stack>

using namespace std;

class StockSpanner {
    // 单调栈
public:
    StockSpanner() {
        idx = 0;
    }

    int next(int price) {
        while (!stk.empty() && stk.top().second <= price) {
            stk.pop();
        }
        int ans;
        if (stk.empty()) {
            ans = idx + 1;
        } else {
            ans = idx - stk.top().first;
        }
        stk.emplace(idx, price);
        ++idx;
        return ans;
    }

private:
    stack<pair<int, int>> stk;
    int idx;  // 下次操作的索引（从0开始）
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0901_H
