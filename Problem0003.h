//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0003_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0003_H

#include <string>
#include <unordered_map>

using namespace std;

class Problem0003 {
private:
    int lengthOfLongestSubstring(const string& s) {
        unordered_map<char, int> charCount;
        int result = 0;
        for (int l = 0, r = 0; r < (int) s.size(); ++r) {
            if (charCount.count(s[r])) {
                ++charCount[s[r]];
            } else {
                charCount[s[r]] = 1;
            }
            while (l < r && charCount[s[r]] > 1) {
                --charCount[s[l]];
                ++l;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0003_H
