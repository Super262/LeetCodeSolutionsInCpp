//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0003_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0003_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        unordered_map<char, int> counter;
        int result = 0;
        for (int l = 0, r = 0; r < (int) s.size(); ++r) {
            ++counter[s[r]];
            while (l < r && counter[s[r]] > 1) {
                --counter[s[l]];
                ++l;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0003_H
