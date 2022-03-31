//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0806_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0806_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, const string &s) {
        vector<int> ans = {1, 0};
        for (const auto &ch: s) {
            ans[1] += widths[ch - 'a'];
            if (ans[1] > 100) {
                ++ans[0];
                ans[1] = widths[ch - 'a'];
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0806_H
