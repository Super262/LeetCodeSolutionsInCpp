//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0575_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0575_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 脑筋急转弯：k = min(n / 2, m)，m是糖果种类，n是糖果个数
public:
    int distributeCandies(const vector<int> &candyType) {
        unordered_set<int> types;
        for (const auto &t: candyType) {
            types.insert(t);
        }
        return min((int) types.size(), (int) (candyType.size() / 2));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0575_H
