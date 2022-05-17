//
// Created by Fengwei Zhang on 5/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0267_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0267_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 首先统计s中各种字符的频率，并记录下出现奇数次的字符single_ch
    // DFS，构造结果的前半部t（不包含single_ch），最终结果为t+single_ch+reversed(t)
    // 细节：'\0'会标识字符串的终点，不能用于拼接字符串（a+'\0'+b）
public:
    vector<string> generatePalindromes(const string &s) {
        unordered_map<char, int> counter;
        for (const auto &ch: s) {
            ++counter[ch];
        }
        bool has_single = false;
        char single_ch = '\0';
        for (auto &item: counter) {
            if (item.second % 2) {
                if (has_single) {
                    return {};
                }
                has_single = true;
                --item.second;
                single_ch = item.first;
            }
        }
        string temp(s.size() / 2, '*');
        vector<string> ans;
        dfs((int) s.size() / 2 - 1, temp, ans, counter);
        for (auto &t: ans) {
            auto r = string(t.rbegin(), t.rend());
            if (has_single) {
                t += single_ch + r;
            } else {
                t += r;
            }
        }
        return ans;
    }

private:
    void dfs(const int i, string &s, vector<string> &ans, unordered_map<char, int> &counter) {
        if (i < 0) {
            ans.emplace_back(s);
            return;
        }
        for (auto &item: counter) {
            if (!item.second) {
                continue;
            }
            s[i] = item.first;
            item.second -= 2;
            dfs(i - 1, s, ans, counter);
            item.second += 2;
            s[i] = '*';
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0267_H
