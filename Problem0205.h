//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0205_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0205_H

#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典算法，直接背诵：验证双射（bijection）是否成立，包含2次验证操作
public:
    bool isIsomorphic(const string &s, const string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> s2t;  // s->t
        unordered_map<char, char> t2s;  // t->s
        for (int i = 0; i < (int) s.size(); ++i) {
            auto a = s[i];
            auto b = t[i];
            if (s2t.count(a) && s2t[a] != b) {  // 第1次判断
                return false;
            }
            s2t[a] = b;
            if (t2s.count(b) && t2s[b] != a) {  // 第2次判断
                return false;
            }
            t2s[b] = a;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0205_H
