//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0451_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0451_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // "桶排序"：先统计每种字符的频率，获得最大频率mf；根据频率，分桶0～mf存放字符；从0到mf，从每个桶取出对应个数的字符并将其加入结果
public:
    string frequencySort(const string &s) {
        unordered_map<char, int> ch_freq;
        unordered_map<int, vector<char>> bucket;
        for (const auto &x: s) {  // 统计每种字符的频率
            ++ch_freq[x];
        }
        int max_freq = 0;
        for (const auto &item: ch_freq) {  // 分桶存放字符
            max_freq = max(max_freq, item.second);
            bucket[item.second].emplace_back(item.first);
        }
        string ans;
        ans.reserve(s.size());
        for (auto f = max_freq; f > 0; --f) {
            if (!bucket.count(f)) {
                continue;
            }
            for (const auto &ch: bucket[f]) {
                for (int k = 0; k < f; ++k) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0451_H
