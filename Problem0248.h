//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0248_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0248_H

#include <string>

using namespace std;

class Solution {
public:
    int strobogrammaticInRange(const string &low, const string &high) {
        int result = 0;
        dfs("", low, high, result);
        dfs("0", low, high, result);
        dfs("1", low, high, result);
        dfs("8", low, high, result);
        return result;
    }

private:
    void dfs(const string &s, const string &low, const string &high, int &result) {
        if (s.size() > high.size()) {
            return;
        }
        if (s.size() >= low.size()) {
            if (isInRange(s, low, high)) {
                ++result;
            }
        }
        if (s.size() + 2 > high.size()) {  // 这个剪枝必须有
            return;
        }
        const string head[] = {"0", "1", "6", "8", "9"};
        const string tail[] = {"0", "1", "9", "8", "6"};
        for (int i = 0; i < 5; ++i) {
            auto temp = head[i] + s + tail[i];
            dfs(temp, low, high, result);
        }
    }

    bool isInRange(const string &s, const string &low, const string &high) {
        if (s.size() > 1 && s[0] == '0') {  // 不合法数字：包含前导0
            return false;
        }
        if (s.size() < low.size()) {  // 太短
            return false;
        }
        if (s.size() > high.size()) {  // 太长
            return false;
        }
        if (s.size() > low.size() && s.size() < high.size()) {  // 在中间
            return true;
        }
        if (low.size() == high.size()) {  // 上下界同长
            return s.compare(low) >= 0 && s.compare(high) <= 0;
        }
        if (low.size() == s.size()) {
            return s.compare(low) >= 0;
        }
        if (high.size() == s.size()) {
            return s.compare(high) <= 0;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0248_H
