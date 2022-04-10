//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0893_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0893_H

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    // 对每个单词，抽取奇数位字符、偶数位字符，分别按字典序排序，生成特征字符串S
    // 若a和b是特殊等价的，则S(a)等于S(b)
public:
    int numSpecialEquivGroups(const vector<string> &words) {
        unordered_set<string> s;
        for (const auto &w: words) {
            string t;
            t.reserve(w.size());
            for (int i = 0; i < (int) w.size(); i += 2) {
                t += w[i];
            }
            sort(t.begin(), t.end());
            auto k = (long) t.size();
            for (int i = 1; i < (int) w.size(); i += 2) {
                t += w[i];
            }
            sort((t.begin() + k), t.end());
            s.insert(t);
        }
        return (int) s.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0893_H
