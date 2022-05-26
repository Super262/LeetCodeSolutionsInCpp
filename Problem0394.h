//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0394_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0394_H

#include <string>
#include <cstring>
#include <cctype>

using namespace std;

class Solution {
    // DFS，维护全局指针
public:
    string decodeString(const string &s) {
        int idx = 0;
        return dfs(s, idx);
    }

private:
    string dfs(const string &s, int &idx) {
        string ans;
        while (idx < s.size() && s[idx] != ']') {  // 递归的终结点是s的末尾或"]"！
            if (isalpha(s[idx])) {
                ans += s[idx];
                ++idx;
            } else {
                auto k = idx;
                while (k < s.size() && isdigit(s[k])) {
                    ++k;
                }
                auto factor = stoi(s.substr(idx, k - idx));
                idx = k + 1;  // 跳过"["
                auto temp = dfs(s, idx);
                ++idx;  // 跳过"]"
                while (factor--) {
                    ans += temp;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0394_H
