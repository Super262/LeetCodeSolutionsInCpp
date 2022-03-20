//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0347_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0347_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(const vector<int> &nums, const int &k) {
        unordered_map<int, int> num_counter;
        for (const auto &x: nums) {  // 统计每个数字的出现次数
            ++num_counter[x];
        }
        const auto n = (int) nums.size();
        vector<int> freq_counter(n + 1, 0);
        for (auto &item: num_counter) {  // 统计每个频次的出现次数
            ++freq_counter[item.second];
        }
        int cur_freq = n;
        int temp = 0;
        while (temp < k) {
            temp += freq_counter[cur_freq];  // 从高到低，计数
            --cur_freq;
        }
        vector<int> res;
        for (auto &item: num_counter) {
            if (item.second <= cur_freq) {
                continue;
            }
            res.emplace_back(item.first);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0347_H
