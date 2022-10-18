//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1013_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1013_H

#include <vector>
#include <numeric>

using namespace std;

class Problem1013 {
    // 我们要寻找最靠左的索引i，最靠右的索引j，以保证sum{0:i} == sum{j:n-1} == sum{0:n-1} / 3，并且i + 1 <= j - 1成立
public:
    bool canThreePartsEqualSum(const vector<int> &arr) {
        auto sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3) {
            return false;
        }
        sum /= 3;
        int i = 0;
        for (int cur = 0; i < (int) arr.size(); ++i) {
            cur += arr[i];
            if (cur == sum) {
                break;
            }
        }
        auto j = (int) arr.size() - 1;
        for (int cur = 0; j >= 0; --j) {
            cur += arr[j];
            if (cur == sum) {
                break;
            }
        }
        return i + 1 <= j - 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1013_H
