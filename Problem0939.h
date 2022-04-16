//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0939_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0939_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 枚举矩形的左上角和右下角，再查找左下角和右上角；
    // 查找基于哈希，要将点对放入哈希表，我们要自己定义哈希函数
public:
    int minAreaRect(const vector<vector<int>> &points) {
        unordered_set<long long> s;
        for (const auto &p: points) {
            s.insert(hashValue(p[0], p[1]));
        }
        int ans = INT_MAX;
        for (int i = 0; i < (int) points.size(); ++i) {
            for (auto j = i + 1; j < (int) points.size(); ++j) {
                const auto &a = points[i];  // 左上角和右下角
                const auto &b = points[j];
                if (a[0] == b[0] || a[1] == b[1]) {
                    continue;
                }
                // 查找左下角和右上角
                if (!s.count(hashValue(b[0], a[1])) || !s.count(hashValue(a[0], b[1]))) {
                    continue;
                }
                ans = min(ans, abs(a[0] - b[0]) * abs(a[1] - b[1]));
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }

private:
    static long long hashValue(int x, int y) {
        return x + 50000 * y;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0939_H
