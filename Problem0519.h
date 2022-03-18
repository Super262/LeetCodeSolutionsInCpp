//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0519_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0519_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 映射二维到一维，利用Map保存1的位置和它的替换位置：https://www.acwing.com/solution/content/24184/
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        k = m * n;
    }

    vector<int> flip() {
        auto x = (int) (random() % k);
        auto t = x;
        if (next_zero_idx.count(t)) {  // 测试位置x
            t = next_zero_idx[t];
        }
        // 测试可能的后继位置k-1
        if (next_zero_idx.count(k - 1)) { // k-1位置被占用
            next_zero_idx[x] = next_zero_idx[k - 1];
            next_zero_idx.erase(k - 1);
        } else {
            next_zero_idx[x] = k - 1;
        }
        --k;
        return {t / n, t % n};
    }

    void reset() {
        k = m * n;
        next_zero_idx.clear();
    }

private:
    int m, n, k;
    unordered_map<int, int> next_zero_idx;  // (x,nx)：x位置是1，nx是0
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0519_H
