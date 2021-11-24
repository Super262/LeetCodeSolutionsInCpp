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
        unordered_map<int, int> numCounter;
        for (const auto &x: nums) {  // 统计每个数字的出现次数
            ++numCounter[x];
        }
        const auto n = (int) nums.size();
        vector<int> freqCounter(n + 1, 0);
        for (auto &item: numCounter) {  // 统计每个频次的出现次数
            ++freqCounter[item.second];
        }
        int currentFreq = n;
        int temp = 0;
        while (temp < k) {
            temp += freqCounter[currentFreq];  // 从高到低，计数
            --currentFreq;
        }
        vector<int> res;
        for (auto &item: numCounter) {
            if (item.second <= currentFreq) {
                continue;
            }
            res.push_back(item.first);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0347_H
