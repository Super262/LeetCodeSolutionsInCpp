//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0440_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0440_H

#include <string>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/6248/
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            auto cnt = commonNumsCount(prefix, n);
            if (k > cnt) {
                k -= cnt;
                ++prefix;
            } else {
                --k;
                prefix *= 10;
            }
        }
        return prefix;
    }

private:
    int commonNumsCount(long long prefix, int n) {  // 1~n中有多少个数以prefix开头
        int k = 1;
        int result = 0;
        while (prefix * 10 <= n) {
            prefix *= 10;
            result += k;
            k *= 10;
        }
        if (prefix <= n) {
            if (n - prefix < k) {
                result += (int) (n - prefix + 1);
            } else {
                result += k;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0440_H
