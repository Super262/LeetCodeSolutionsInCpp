//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0233_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0233_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0233 {
private:
    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> digits;
        while (n > 0) {
            digits.emplace_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        int result = 0;
        for (int i = 0; i < digits.size(); ++i) {
            int leftNum = 0;
            int rightNum = 0;
            for (int j = 0; j < i; ++j) {
                leftNum = leftNum * 10 + digits[j];
            }
            int rightBase = 1;
            for (int j = i + 1; j < digits.size(); ++j) {
                rightNum = rightNum * 10 + digits[j];
                rightBase *= 10;
            }
            if (digits[i] == 1) {
                result += leftNum * rightBase + rightNum + 1;
            } else if (digits[i] == 0) {
                result += leftNum * rightBase;
            } else {
                result += (leftNum + 1) * rightBase;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0233_H
