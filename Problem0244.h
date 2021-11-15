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
private:
    unordered_map<string, vector<int>> locations;

public:
    WordDistance(const vector<string> &dict) {
        // 预存每个单词出现的位置
        for (int i = 0; i < (int) dict.size(); ++i) {
            if (!locations.count(dict[i])) {
                locations[dict[i]] = vector<int>();
            }
            locations[dict[i]].emplace_back(i);
        }
    }

    int shortest(const string &w1, const string &w2) {
        int result = INT_MAX;
        // 巧妙解法，利用locations的天然有序性
        int p1 = 0;
        int p2 = 0;
        while (p1 < (int) locations[w1].size() && p2 < (int) locations[w2].size()) {
            result = min(result, abs(locations[w1][p1] - locations[w2][p2]));
            if (locations[w1][p1] > locations[w2][p2]) {
                ++p2;
            } else {
                ++p1;
            }
        }
        return result;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0244_H
