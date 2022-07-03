//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0659_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0659_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 贪心思想，若x可接在某个链后，则将x加入此链，即{... x-1, x}；否则，以x为起点构建新链{x, x+1, x+2}
    // 若当前没有以x-1结尾的链，也无法构造新链{x,x+1,x+2}，直接返回false
public:
    bool isPossible(const vector<int> &nums) {
        unordered_map<int, int> num_cnt;  // 统计每个数x的频次
        unordered_map<int, int> tail_cnt;  // 统计以结尾是x的链的频次
        for (const auto &x: nums) {
            ++num_cnt[x];
        }
        for (const auto &x: nums) {
            if (!num_cnt.count(x) || !num_cnt[x]) {
                continue;
            }
            if (tail_cnt.count(x - 1) && tail_cnt[x - 1]) {
                --num_cnt[x];
                --tail_cnt[x - 1];
                ++tail_cnt[x];
            } else if (num_cnt.count(x + 1) && num_cnt[x + 1] && num_cnt.count(x + 2) && num_cnt[x + 2]) {
                --num_cnt[x + 1];
                --num_cnt[x + 2];
                --num_cnt[x];
                ++tail_cnt[x + 2];
            } else {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0659_H
