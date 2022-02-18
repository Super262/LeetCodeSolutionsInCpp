//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0661_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0661_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(const vector<vector<int>> &img) {
        vector<vector<int>> res(img);
        const auto m = (int) img.size();
        const auto n = (int) img[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int counter = 0;
                for (auto x = i - 1; x <= i + 1; ++x) {
                    for (auto y = j - 1; y <= j + 1; ++y) {
                        if (x < 0 || y < 0 || x >= m || y >= n) {
                            continue;
                        }
                        sum += img[x][y];
                        ++counter;
                    }
                }
                res[i][j] = sum / counter;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0661_H
