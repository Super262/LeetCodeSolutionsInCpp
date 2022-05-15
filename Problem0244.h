//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0244_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0244_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class WordDistance {
    // locations预存每个单词出现的位置序列（相同单词重复出现）
    // 贪心算法：利用locations[w]的天然有序性
public:
    WordDistance(const vector<string> &dict) {
        for (int i = 0; i < (int) dict.size(); ++i) {
            locations[dict[i]].emplace_back(i);
        }
    }

    int shortest(const string &w1, const string &w2) {
        int ans = INT_MAX;
        int p1 = 0;
        int p2 = 0;
        while (p1 < (int) locations[w1].size() && p2 < (int) locations[w2].size()) {
            ans = min(ans, abs(locations[w1][p1] - locations[w2][p2]));
            if (locations[w1][p1] > locations[w2][p2]) {  // p2追近p1
                ++p2;
            } else {  // p1追近p2
                ++p1;
            }
        }
        return ans;
    }

private:
    unordered_map<string, vector<int>> locations;
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0244_H
