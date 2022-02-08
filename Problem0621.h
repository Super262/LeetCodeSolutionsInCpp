//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0621_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0621_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典算法，直接背诵：贪心
    // https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
public:
    int leastInterval(const vector<char> &tasks, const int n) {
        unordered_map<char, int> counter;
        for (const char &ch: tasks) {
            ++counter[ch];
        }
        int max_freq = 0;  // 桶的数量
        int max_cnt = 0;  // 任务种类数 == 最后一桶的任务数
        for (const auto &item: counter) {
            max_freq = max(item.second, max_freq);
        }
        for (const auto &item: counter) {
            if (item.second == max_freq) {
                ++max_cnt;
            }
        }
        return max((int) tasks.size(), (max_freq - 1) * (n + 1) + max_cnt);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0621_H
