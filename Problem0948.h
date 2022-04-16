//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0948_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0948_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心算法：每次选择最小的令牌来获得更多分数，能量不足时选择最大的令牌来获得最多的分数
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        // [l:r]是当前的候选区间：l指向最小值，r指向最大值
        auto l = 0;
        auto r = (int) tokens.size() - 1;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                ++l;
                ++score;
                continue;
            }
            if (r == l || !score) {  // 没有可行的选择
                return 0;
            }
            power += tokens[r];
            --r;
            --score;
        }
        return score;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0948_H
