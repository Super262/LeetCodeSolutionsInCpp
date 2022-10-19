//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0997_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0997_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0997 {
    // 统计入度和出度，返回满足题意的点
public:
    int findJudge(int n, const vector<vector<int>> &trust) {
        int din[n + 1];
        int dout[n + 1];
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        for (const auto &t: trust) {
            ++din[t[1]];
            ++dout[t[0]];
        }
        for (int i = 1; i <= n; ++i) {
            if (!dout[i] && din[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0997_H
