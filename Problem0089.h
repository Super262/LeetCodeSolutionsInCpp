//
// Created by Fengwei Zhang on 10/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0089_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0089_H

#include <vector>

using namespace std;

class Problem0089 {
public:
    vector<int> grayCode(int n) {
        // 特殊规律，要牢记
        vector<int> res(1, 0);
        while (n--) {
            for (int i = (int) res.size() - 1; i >= 0; --i) {
                res[i] *= 2;
                res.emplace_back(res[i] + 1);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0089_H
