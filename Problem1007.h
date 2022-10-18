//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1007_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1007_H

#include <vector>
#include <cstring>

using namespace std;

class Problem1007 {
    // 遍历1次将每层的每种点数x的数目算出来；不要忽略上下相等的骨牌的数量all_same
    // 若top[x] + bottom[x] - all_same >= n，x可能成为目标值
public:
    int minDominoRotations(const vector<int> &tops, const vector<int> &bottoms) {
        const auto n = (int) tops.size();
        const int m = 6;
        int top_cnt[m + 1];
        int bot_cnt[m + 1];
        memset(top_cnt, 0, sizeof top_cnt);
        memset(bot_cnt, 0, sizeof bot_cnt);
        int all_same = 0;
        for (int i = 0; i < n; ++i) {
            ++top_cnt[tops[i]];
            ++bot_cnt[bottoms[i]];
            if (bottoms[i] == tops[i]) {
                ++all_same;
            }
        }
        int ans = INT_MAX;
        for (int x = 1; x <= m; ++x) {
            if (top_cnt[x] + bot_cnt[x] - all_same < n) {
                continue;
            }
            ans = min(ans, min(n - top_cnt[x], n - bot_cnt[x]));
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1007_H
