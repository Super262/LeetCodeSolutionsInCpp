//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0351_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0351_H

#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    // 枚举序列长度，从m到n，直接DFS；根据前驱判断当前选择是否合法，最后累加答案
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        bool used[K];  // used[i]：数字i是否被使用
        for (auto length = m; length <= n; ++length) {
            memset(used, 0, sizeof used);
            ans += dfs(length, 0, used);
        }
        return ans;
    }

private:
    const int K = 10;

    int dfs(int length, int prev, bool used[]) {  // prev是上个被使用的数字
        if (!length) {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i < K; ++i) {
            if (used[i] || !isValid(prev, i, used)) {
                continue;
            }
            used[i] = true;
            ans += dfs(length - 1, i, used);
            used[i] = false;
        }
        return ans;
    }

    bool isValid(int prev, int cur, bool used[]) {
        if (!prev) {
            return true;
        }
        if (prev > cur) {  // 我们默认prev大于cur
            swap(prev, cur);
        }
        if (prev == 1 && cur == 3) {  // (1,3)的中点是2
            return used[2];
        }
        if (prev == 1 && cur == 7) {  // (1,7)的中点是4
            return used[4];
        }
        if (prev == 3 && cur == 9) {  // (3,9)的中点是6
            return used[6];
        }
        if (prev == 7 && cur == 9) {  // (7,9)的中点是8
            return used[8];
        }
        // (4,6)、(2,8)、(1,9)、(3,7)的中点是5
        if ((prev == 4 && cur == 6) || (prev == 2 && cur == 8) || (prev == 1 && cur == 9) || (prev == 3 && cur == 7)) {
            return used[5];
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0351_H
