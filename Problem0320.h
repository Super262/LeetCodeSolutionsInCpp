//
// Created by Fengwei Zhang on 5/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0320_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0320_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 直接DFS，每个字符有2种状态：被缩写、被保留
    // 因此我们除了要记录当前步搜索的起点，还要记录上步有多少个字符被缩写（非常巧妙）
public:
    vector<string> generateAbbreviations(const string &word) {
        vector<string> ans;
        string cur;
        dfs(0, 0, cur, word, ans);
        return ans;
    }

private:
    void dfs(int i, int k, string &cur, const string &word, vector<string> &ans) {  // i是搜索的起点，k是上步被缩写的字符个数
        auto prev_len = (int) cur.size();
        if (i >= (int) word.size()) {
            if (k) {
                cur += to_string(k);
            }
            ans.emplace_back(cur);
        } else {
            dfs(i + 1, k + 1, cur, word, ans);
            if (k) {
                cur += to_string(k);
            }
            cur += word[i];
            dfs(i + 1, 0, cur, word, ans);
        }
        cur.erase(cur.begin() + prev_len, cur.end());
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0320_H
