//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1002_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1002_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem1002 {
    // 统计每个字符串中的字符种类和频率，记录全局最小值并输出
public:
    vector<string> commonChars(const vector<string> &words) {
        const int m = 26;
        int global_cnt[m];  // 全局最小值
        memset(global_cnt, 0x3f, sizeof global_cnt);
        for (const auto &w: words) {
            int temp_cnt[m];  // 当前单词的字符频率
            memset(temp_cnt, 0, sizeof temp_cnt);
            for (const auto &ch: w) {
                ++temp_cnt[ch - 'a'];
            }
            for (int i = 0; i < m; ++i) {
                global_cnt[i] = min(global_cnt[i], temp_cnt[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < m; ++i) {
            if (!global_cnt[i]) {
                continue;
            }
            for (int j = 0; j < global_cnt[i]; ++j) {
                ans.emplace_back(string(1, (char) ('a' + i)));
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1002_H
