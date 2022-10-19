//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0986_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0986_H

#include <vector>

using namespace std;

class Problem0986 {
    // 双指针算法：i指向first头部、j指向second头部，设i指向(a,b)、j指向(c,d)
    // 设i、j的交集为(x,y)：若y=b，i后移；若y=d，j后移
public:
    vector<vector<int>> intervalIntersection(const vector<vector<int>> &first, const vector<vector<int>> &second) {
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while (i < (int) first.size() && j < (int) second.size()) {
            auto a = first[i][0];
            auto b = first[i][1];
            auto c = second[j][0];
            auto d = second[j][1];
            if (b < c) {  // (a,b)在(c,d)前，无交集
                ++i;
                continue;
            }
            if (d < a) {  // (c,d)在(a,b)前，无交集
                ++j;
                continue;
            }
            auto x = max(a, c);
            auto y = min(b, d);
            ans.push_back({x, y});
            if (y == b) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0986_H
