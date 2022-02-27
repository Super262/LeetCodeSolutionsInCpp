//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0771_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0771_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(const string &jewels, const string &stones) {
        unordered_set<char> jew_set(jewels.begin(), jewels.end());
        int res = 0;
        for (const auto &s: stones) {
            if (jew_set.count(s)) {
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0771_H
