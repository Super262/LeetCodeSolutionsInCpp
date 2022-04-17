//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0957_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0957_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 由于n可能很大（10^9），我们不能直接迭代n次；我们选择探索循环节，即发现f[j] = f[i]（i < j）
    // f[s] = i，状态s会在第i步取得
public:
    vector<int> prisonAfterNDays(const vector<int> &cells, int n) {
        int s = 0;
        const auto m = (int) cells.size();
        int f[1 << m];
        memset(f, -1, sizeof f);
        for (const auto &x: cells) {  // 生成初始状态
            s <<= 1;
            s += x;
        }
        f[s] = 0;
        for (int i = 1; n > 0; ++i) {  // 深刻体会此循环内的代码
            auto ns = nextState(s, m);
            --n;
            if (f[ns] != -1) {  // 发现循环节，调整n
                n %= i - f[ns];
            } else {
                f[ns] = i;
            }
            s = ns;
        }
        return toVector(s, m);
    }

private:
    static int nextState(int s, int n) {
        int ans = 0;
        for (auto i = n - 1; i >= 0; --i) {
            ans <<= 1;
            if (i == n - 1 || !i) {  // 第0位和最后一位永远为空
                continue;
            }
            if (((s >> (i - 1)) & 1) != ((s >> (i + 1)) & 1)) {
                continue;
            }
            ++ans;
        }
        return ans;
    }

    static vector<int> toVector(int s, int n) {
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = (s >> (n - i - 1)) & 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0957_H
