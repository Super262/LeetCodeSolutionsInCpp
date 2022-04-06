//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0848_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0848_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 我们观察到：s[n-1]向后移动的位数为shifts[n-1]，s[n-2]向后移动的位数为(shifts[n-2]+shifts[n-1])
public:
    string shiftingLetters(const string &s, const vector<int> &shifts) {
        string ans;
        int prefix = 0;
        ans.reserve(s.size());
        for (auto i = (int) s.size() - 1; i >= 0; --i) {
            prefix = (prefix + shifts[i]) % 26;
            ans += (char) ((s[i] - 'a' + prefix) % 26 + 'a');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0848_H
