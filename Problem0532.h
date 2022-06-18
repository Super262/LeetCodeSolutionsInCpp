//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0532_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0532_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 哈希表counter统计每种数字的频率；对于数字x，若k为0且counter[x]>1，答案加1；若k>0且counter[x-k]>0，答案加1
public:
    int findPairs(const vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        for (const auto &x: nums) {
            counter[x]++;
        }
        int ans = 0;
        for (const auto &item: counter) {
            if (k == 0) {
                if (item.second > 1) {
                    ++ans;
                }
            } else {
                if (counter.count(item.first - k)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0532_H
