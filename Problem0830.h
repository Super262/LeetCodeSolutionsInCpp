//
// Created by Fengwei Zhang on 4/2/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0830_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0830_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(const string &s) {
        vector<vector<int>> ans;
        for (int i = 0; i < s.size(); ++i) {
            auto j = i;
            while (j < s.size() && s[j] == s[i]) {
                ++j;
            }
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0830_H
