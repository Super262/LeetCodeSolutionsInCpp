//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0771_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0771_H

#include <string>
#include <unordered_set>

using namespace std;

class Problem0771 {
    // 哈希表，直接遍历
public:
    int numJewelsInStones(const string &jewels, const string &stones) {
        unordered_set<char> jew_set(jewels.begin(), jewels.end());
        int ans = 0;
        for (const auto &s: stones) {
            if (jew_set.count(s)) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0771_H
