//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0168_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0168_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，直接背诵：映射1~26到A~Z
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            n--;
            ans += (char) (n % 26 + 'A');
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0168_H
