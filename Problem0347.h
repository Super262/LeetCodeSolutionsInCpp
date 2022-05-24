//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0347_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0347_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 首先统计每种数字的频率f；再统计所有频次的频率f'；为保持时间复杂度为O(n)，我们不会对所有f'排序
    // 易知f'最大值为n（数组的长度），我们从n开始递减统计f'，找到第k个；再根据第k个f'，筛选出满足条件的元素
public:
    vector<int> topKFrequent(const vector<int> &nums, const int &k) {
        unordered_map<int, int> num_counter;
        for (const auto &x: nums) {  // 统计每个数字的出现次数
            ++num_counter[x];
        }
        const auto n = (int) nums.size();
        vector<int> freq_counter(n + 1, 0);
        for (const auto &item: num_counter) {  // 统计每个频次的出现次数
            ++freq_counter[item.second];
        }
        int cur_freq = n;
        int cnt = 0;
        while (cnt < k) {
            cnt += freq_counter[cur_freq];  // 从高到低，计数
            --cur_freq;
        }
        vector<int> ans;
        for (const auto &item: num_counter) {
            if (item.second <= cur_freq) {
                continue;
            }
            ans.emplace_back(item.first);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0347_H
