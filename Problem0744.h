//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0744_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0744_H

#include <vector>

using namespace std;

class Problem0744 {
    // 因为输入序列是有序的，我们二分查找第1个大于t的字符letters[r]；若letters[r]小于或等于t，我们返回letters[0]
public:
    char nextGreatestLetter(const vector<char> &letters, const char t) {
        int l = 0;
        auto r = (int) letters.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (letters[mid] > t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (letters[r] <= t) {
            return letters[0];
        }
        return letters[r];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0744_H
