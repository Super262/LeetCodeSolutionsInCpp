//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0119_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0119_H

#include <vector>

using namespace std;

class Problem0119 {
public:
    vector<int> getRow(const int &rowIndex) {
        vector<vector<int>> f(2, vector<int>(rowIndex + 1, 1));
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                f[i % 2][j] = f[(i - 1) % 2][j] + f[(i - 1) % 2][j - 1];
            }
        }
        return f[rowIndex % 2];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0119_H
