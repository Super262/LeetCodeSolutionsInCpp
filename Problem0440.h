//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0440_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0440_H

#include <string>

using namespace std;

class Solution {
    // 依照字典序，从小到大统计每个前缀的频率cnt，若k>cnt，我们尝试下个前缀，直到找到前缀prefix，prefix是第k个数的前缀
    // https://www.acwing.com/solution/content/6248/，时间复杂度：10(LogN)^2
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            auto cnt = prefixCount(prefix, n);
            if (k > cnt) {
                k -= cnt;
                ++prefix;  // 切换到下组
            } else {
                prefix *= 10;  // prefix的下个前缀是prefix*10
                --k;
            }
        }
        return prefix;
    }

private:
    int prefixCount(long long prefix, int n) {  // 1~n中有多少个数以prefix开头
        int k = 1;
        int ans = 0;
        while (prefix * 10 <= n) {
            prefix *= 10;
            ans += k;
            k *= 10;
        }
        if (prefix <= n) {
            if (n - prefix < k) {
                ans += (int) (n - prefix + 1);
            } else {
                ans += k;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0440_H
