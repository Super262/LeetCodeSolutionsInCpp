//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0245_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0245_H

#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestWordDistance(const vector<string> &dict, const string &w1, const string &w2) {
        vector<int> locations1;
        vector<int> locations2;
        for (int i = 0; i < (int) dict.size(); ++i) {
            if (dict[i] == w1) {
                locations1.emplace_back(i);
            } else if (dict[i] == w2) {
                locations2.emplace_back(i);
            }
        }
        int result = INT_MAX;
        if (w1 == w2) {
            if (locations1.size() > 1) {
                for (int i = 1; i < (int) locations1.size(); ++i) {
                    result = min(result, abs(locations1[i] - locations1[i - 1]));
                }
            }
        } else {
            int p1 = 0;
            int p2 = 0;
            while (p1 < (int) locations1.size() && p2 < (int) locations2.size()) {
                result = min(result, abs(locations1[p1] - locations2[p2]));
                if (locations1[p1] > locations2[p2]) {
                    ++p2;
                } else {
                    ++p1;
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0245_H
