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
    // 我们从高位到低位依次生成n个数，形成最终结果ans；设i的阶乘为f(i)
    // 对于结果ans中的第i位（0<=i<=n-1），若尝试将第i位设置为x，若k>f(i)，我们应尝试x+1，并更新k=k-f(n-i-1)
    // 若k<=f(n-i-1)，设置第i位为x，标记x以避免重复，继续尝试第i+1位
public:
    string getPermutation(int n, int k) {
        int factorial[n + 1];  // 预计算n!（由n个数字组成的、各位不重复的n位数有n!个）
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        bool used[n + 1];  // 标识当前数字是否已经被使用过
        string ans;
        ans.reserve(n);
        memset(used, 0, sizeof used);
        for (int i = 0; i < n; ++i) {  // 从高位到低位，填充结果
            for (int digit = 1; digit <= n; ++digit) {  // 由小到大，尝试每个数字
                if (used[digit]) {
                    continue;
                }
                if (k > factorial[n - i - 1]) {  // 检测k是否大于以当前数字开头的(n-i-1)位数的个数
                    k -= factorial[n - i - 1];
                    continue;
                }
                ans += (char) ('0' + digit);
                used[digit] = true;
                break;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0060_H
