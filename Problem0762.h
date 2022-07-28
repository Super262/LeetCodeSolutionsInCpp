//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0762_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0762_H

#include <unordered_set>

using namespace std;

class Problem0762 {
    // 枚举[l:r]中每个数字，验证它是否有质数个1；我们用哈希表存储[2:31]内所有质数，便于判断
public:
    int countPrimeSetBits(int l, int r) {
        if (l > r) {
            return 0;
        }
        unordered_set<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});
        int ans = 0;
        for (auto i = l; i <= r; ++i) {
            int counter = 0;
            for (auto j = lowBit(i); j > 0; j -= lowBit(j)) {
                ++counter;
            }
            if (primes.count(counter)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    int lowBit(int x) {
        return x & -x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0762_H
