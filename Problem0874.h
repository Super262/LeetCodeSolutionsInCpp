//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0874_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0874_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    // 直接模拟，结合方向数组；使用哈希表高效保存离散的位置
public:
    int robotSim(const vector<int> &commands, const vector<vector<int>> &obstacles) {
        unordered_set<string> s;
        for (const auto &p: obstacles) {
            s.insert(getPoint(p[0], p[1]));
        }
        const int m = 4;
        const int dx[m] = {0, 1, 0, -1};
        const int dy[m] = {1, 0, -1, 0};
        int ans = 0;
        int x = 0;
        int y = 0;
        int i = 0;
        for (const auto &c: commands) {
            if (c == -2) {  // 左转
                i = ((i - 1) % m + m) % m;
                continue;
            }
            if (c == -1) {  // 右转
                i = ((i + 1) % m + m) % m;
                continue;
            }
            for (int j = 0; j < c; ++j) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                if (s.count(getPoint(nx, ny))) {  // 遇到障碍物，直接停下
                    break;
                }
                x = nx;
                y = ny;
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }

private:
    static string getPoint(int x, int y) {
        return to_string(x) + " # " + to_string(y);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0874_H
