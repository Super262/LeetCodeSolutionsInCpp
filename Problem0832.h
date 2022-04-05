//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0832_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0832_H

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
        for (auto &row: image) {
            reverse(row.begin(), row.end());
            for (auto &x: row) {
                x ^= 1;
            }
        }
        return image;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0832_H
