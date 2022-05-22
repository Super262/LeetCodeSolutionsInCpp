//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0316_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0316_H

#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 贪心算法：保持次序，尽量将较大的字符放在尾部；设ans是当前的结果字符串，a是我们当前在s遍历到的字符，b是ans最后的字符
    // 若ans包含a，跳过a；若b>a，且b还会在a后面出现，我们删除b；重复此步骤，直到条件不满足
    // 若b<a，将a加入ans尾部
public:
    string removeDuplicateLetters(const string &s) {
        bool is_in_ans[26];
        int last_idx[26];
        memset(is_in_ans, 0, sizeof is_in_ans);
        memset(last_idx, -1, sizeof last_idx);
        for (int i = 0; i < (int) s.size(); ++i) {
            last_idx[s[i] - 'a'] = i;
        }
        string ans;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (is_in_ans[s[i] - 'a']) {
                continue;
            }
            while (!ans.empty() && ans.back() > s[i] && last_idx[ans.back() - 'a'] > i) {
                is_in_ans[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += s[i];
            is_in_ans[s[i] - 'a'] = true;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0316_H
