//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0899_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0899_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 当 K == 1 时，显然我们只能每次将开头的一次字符移动到末尾，这样我们的备选答案一共就只有 n 种，枚举每一种找到字典序最小的即可。
    // 当 K > 1 时，可以证明其可以转换为任意的串。假设我们希望交换 S[i] 和 S[i + 1]，只需要将 [0, i- 1] 的字符移动到末尾，
    // 然后将 S[i + 1] 移动到末尾，再将 S[i] 移动到末尾，再将 [i + 2, n - 1] 移动到末尾。
    // 有了交换相邻字符的操作，可以利用冒泡排序排出字典序最小的串。
public:
    string orderlyQueue(const string &s, int k) {
        auto ans = s;
        if (k == 1) {
            auto t = s;
            for (int i = 0; i < (int) s.size(); ++i) {
                t = t.substr(1) + t[0];
                ans = min(ans, t);
            }
            return ans;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0899_H
