//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0985_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0985_H

#include <vector>
#include <numeric>

using namespace std;

class Problem0985 {
    // 直接模拟：若a是偶数，a+val是奇数，则sum-=a；若a+val是偶数，sum+=val。若a是奇数、a+val是偶数，sum+=a+val
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, const vector<vector<int>> &queries) {
        int cur_sum = 0;
        for (const auto &x: nums) {
            if (x % 2) {
                continue;
            }
            cur_sum += x;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < (int) queries.size(); ++i) {
            auto j = queries[i][1];
            auto val = queries[i][0];
            if (nums[j] % 2) {
                if ((nums[j] + val) % 2 == 0) {
                    cur_sum += nums[j] + val;
                }
            } else {
                if ((nums[j] + val) % 2 == 0) {
                    cur_sum += val;
                } else {
                    cur_sum -= nums[j];
                }
            }
            nums[j] += val;
            ans[i] = cur_sum;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0985_H
