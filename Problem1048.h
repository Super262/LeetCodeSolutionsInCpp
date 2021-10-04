//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1048_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1048_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

class Problem1048 {
private:
    // 动态规划：dp[i]是以words[i]结尾的的最长字符串链长度
    static bool compare(const string &a, const string &b) {
        return a.size() < b.size();
    }

    bool isPrev(const string &cur, const string &next) {
        if (cur.size() + 1 != next.size()) {
            return false;
        }
        int i = 0, j = 0;
        while (i < cur.size() && j < next.size()) {
            if (cur[i] == next[j]) {
                ++i;
            }
            ++j;
        }
        if (i < cur.size()) {
            return false;
        }
        return true;
    }

    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), compare);

        int dp[words.size()];
        memset(dp, 0, sizeof dp);

        int result = 0;
        for (int i = 0; i < (int) words.size(); ++i) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (!isPrev(words[j], words[i])) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1048_H
