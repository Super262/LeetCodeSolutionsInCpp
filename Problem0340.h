//
// Created by Fengwei Zhang on 5/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0340_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0340_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 双指针，哈希表记录滑动窗口内的元素种类数
public:
    int lengthOfLongestSubstringKDistinct(const string &s, int k) {
        unordered_map<char, int> counter;
        int ans = 0;
        for (int l = 0, r = 0; r < (int) s.size(); ++r) {
            counter[s[r]]++;
            while (l <= r && (int) counter.size() > k) {
                counter[s[l]]--;
                if (!counter[s[l]]) {
                    counter.erase(s[l]);
                }
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0340_H
