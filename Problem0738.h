//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0738_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0738_H

#include <string>

using namespace std;

class Problem0738 {
    // 我们要找到小于num的、最大的"单调递增"数字（相邻两位x、y满足：x<=y）；贪心：找到数字num的首个非"单调递增"位置k，
    // 递减k，直到出现递增（num[k-1]<num[k]），将num[k]减1，将num[k+1:n-1]所有位设置为'9'
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
