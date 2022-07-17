
//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0728_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0728_H

#include <vector>
#include <string>

using namespace std;

class Problem0728 {
    // 遍历区间[left:right]内所有数字，逐个检查每个数字是否为自除数
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (auto x = left; x <= right; ++x) {
            if (checkSelf(x)) {
                ans.emplace_back(x);
            }
        }
        return ans;
    }

private:
    bool checkSelf(const int &x) {
        auto t = x;
        while (t) {
            auto a = t % 10;
            if (!a || x % a) {
                return false;
            }
            t /= 10;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0728_H
