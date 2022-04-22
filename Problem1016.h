//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1016_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1016_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    // 反向思考，直接枚举s的长度不超过30的子串，如果子串构成了1～n中的数字，则加到一个集合中，最后判断集合的大小是否等于n
public:
    bool queryString(const string &s, int n) {
        unordered_set<int> nums;
        for (int i = 0; i < (int) s.size(); ++i) {  // 从高位开始枚举子串起点
            int cur = 0;
            for (int length = 1; length < 31 && i + length - 1 < (int) s.size(); ++length) {  // 枚举子串长度，向低位扩展
                cur = cur * 2 + (s[i + length - 1] - '0');
                if (cur > n) {
                    break;
                }
                if (cur) {
                    nums.insert(cur);
                }
            }
        }
        return (int) nums.size() == n;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1016_H
