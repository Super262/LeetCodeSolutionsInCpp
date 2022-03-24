
//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0761_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0761_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 贪心算法 + 递归处理：https://www.acwing.com/solution/content/3594/
public:
    string makeLargestSpecial(const string &s) {
        if (s.empty()) {
            return "";
        }
        const auto &n = (int) s.size();
        vector<string> parts;
        for (int l = 0, r = 0, cnt = 0; r < n; ++r) {
            if (s[r] == '1') {
                ++cnt;
            } else {
                --cnt;
            }
            if (!cnt) {
                parts.emplace_back("1" + makeLargestSpecial(s.substr(l + 1, r - l - 1)) + "0");
                l = r + 1;
            }
        }
        sort(parts.rbegin(), parts.rend());
        string ans;
        for (const auto &p: parts) {
            ans += p;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0761_H
