//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0710_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0710_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    // 映射黑名单到白名单：黑名单长度为m，将[0,n-m)分配给白名单，将[n-m,n)作为黑名单的替代
    // https://www.acwing.com/solution/content/4409/
public:
    Solution(int k, vector<int> &black_list) {
        sort(black_list.begin(), black_list.end());
        n = k;
        m = (int) black_list.size();
        auto num = n - m;
        for (const auto &x: black_list) {
            equivalent[x] = -1;
        }
        for (const auto &x: black_list) {
            if (x >= n - m) {
                break;
            }
            while (equivalent.count(num)) {
                ++num;
            }
            equivalent[x] = num;
            ++num;
        }
    }

    int pick() {
        auto x = (int) (random() % (n - m));
        if (equivalent.count(x)) {
            return equivalent[x];
        }
        return x;
    }

private:
    int n;  // 随机数范围为[0,n)
    int m;  // 黑名单长度
    unordered_map<int, int> equivalent;  // 黑名单数的替代
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0710_H
