//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0519_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0519_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 映射二维到一维，利用Map保存1的位置和它的替换位置；设k是当前可用的位置的个数，0<=k<=m*n
    // 我们将二维坐标映射到一维坐标i，满足0<=i<=k-1；映射next_zero_idx[i]表示当位置i为1时，位置i对应的为0的位置
    // 函数flip：生成随机数x，0<=x<=k-1；若位置x被占用，更新位置x为next_zero_idx[x]
    // 此时位置x为1，我们需要设置位置x的后继；若位置k-1被占用，x的后继为next_zero_idx[k - 1]；若k-1未被占用，x的后继为k-1
    // https://www.acwing.com/solution/content/24184/
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
