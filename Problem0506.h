//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0506_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0506_H

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    // 将score[i]和索引i组合为(score[i],i)，降序排序，依次为ans[i]设置名次
public:
    vector<string> findRelativeRanks(const vector<int> &score) {
        vector<pair<int, int>> pairs(score.size());
        for (int i = 0; i < score.size(); ++i) {
            pairs[i].first = score[i];
            pairs[i].second = i;
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
        vector<string> ans(score.size());
        string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < 3 && i < pairs.size(); ++i) {
            ans[pairs[i].second] = medals[i];
        }
        for (int i = 3; i < pairs.size(); ++i) {
            ans[pairs[i].second] = to_string(i + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0506_H
