//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0205_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0205_H

#include <cstring>
#include <string>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    bool isIsomorphic(const string &s, const string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        int s2t[256];
        int t2s[256];
        memset(s2t, -1, sizeof s2t);
        memset(t2s, -1, sizeof t2s);
        for (int i = 0; i < (int) s.size(); ++i) {
            auto a = s[i];
            auto b = t[i];
            if (s2t[a] != -1 && s2t[a] != b) {  // 第1次判断
                return false;
            }
            s2t[a] = (int) (unsigned char) b;
            if (t2s[b] != -1 && t2s[b] != a) {  // 第2次判断
                return false;
            }
            t2s[b] = (int) (unsigned char) a;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0205_H
