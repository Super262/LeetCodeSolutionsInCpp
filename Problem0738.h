//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0738_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0738_H

#include <string>

using namespace std;

class Solution {
    // 直接背诵：找到第一个递减位置，将后面数字全部置为9
public:
    int monotoneIncreasingDigits(int n) {
        auto num = to_string(n);
        int k = 0;
        while (k + 1 < (int) num.size() && num[k] <= num[k + 1]) {
            ++k;
        }
        if (k + 1 == (int) num.size()) {
            return n;
        }
        while (k && num[k - 1] == num[k]) {
            --k;
        }
        --num[k];
        for (int i = k + 1; i < (int) num.size(); ++i) {
            num[i] = '9';
        }
        return stoi(num);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0738_H
