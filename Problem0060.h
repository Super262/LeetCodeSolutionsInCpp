//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0060_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0060_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0060 {
private:
    string getPermutation(int n, int k) {
        string result;
        int factorial[n + 1];
        bool used[n + 1];

        // 预计算n!（n个数字可组成的n位数有n!个）
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        memset(used, 0, sizeof used);
        for (int i = 0; i < n; ++i) {
            for (int digit = 1; digit <= n; ++digit) {
                if (used[digit]) {  // 检测当前数字是否已经被使用过
                    continue;
                }
                if (k > factorial[n - i - 1]) {  // 检测k是否大于以当前数字开头的n位数的个数
                    k -= factorial[n - i - 1];
                } else {
                    result.push_back((char) ('0' + digit));
                    used[digit] = true;
                    break;
                }
            }
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0060_H
