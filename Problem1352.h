//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1352_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1352_H

#include <vector>

using namespace std;

class ProductOfNumbers {
private:
    // 技巧：遇到0的时候，直接清空前缀数组
    vector<int> prefix;
    int tt;

public:
    ProductOfNumbers() {
        prefix.emplace_back(1);  // prefix[0] = 1
        tt = 0;
    }

    void add(int num) {
        if (num == 0) {  // 清空prefix数组
            tt = 0;
            return;
        }
        if (tt + 1 >= prefix.size()) {  // 数组扩容
            prefix.emplace_back(0);
        }
        prefix[++tt] = num;
        prefix[tt] *= prefix[tt - 1];
    }

    int getProduct(int k) {
        if (k > tt) {
            return 0;
        }
        return prefix[tt] / prefix[tt - k];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1352_H
