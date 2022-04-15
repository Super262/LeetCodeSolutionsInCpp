//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0932_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0932_H

#include <vector>

using namespace std;

class Solution {
    // 经典分治算法：不断在数组的两部分进行奇偶分离
    // https://www.acwing.com/solution/content/588/
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans(n);
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = i + 1;
        }
        divideConquer(0, n - 1, ans, temp);
        return ans;
    }

private:
    void divideConquer(int l, int r, vector<int> &ans, vector<int> &temp) {
        if (l >= r) {
            return;
        }
        // 奇数在前，偶数在后
        auto j = l;
        for (auto i = l; i <= r; i += 2, ++j) {
            temp[j] = ans[i];
        }
        for (auto i = l + 1; i <= r; i += 2, ++j) {
            temp[j] = ans[i];
        }
        copy(temp.begin() + l, temp.begin() + (r + 1), ans.begin() + l);
        auto mid = l + (r - l) / 2;
        divideConquer(l, mid, ans, temp);
        divideConquer(mid + 1, r, ans, temp);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0932_H
