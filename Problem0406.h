//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0406_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0406_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 贪心算法：设输入的每项是(h,k)，h是身高，k是前缀中身高不低于h的人的数量
    // 我们每次选出身高最小的人，将它放到位置i，queue[0:i-1]刚好有k个空位；对于身高相同的两人，我们应将k更大的人放在前面
    // 设队列中空位为0，被占的位置为1，向队列的位置i加入新人后，前缀和prefix[i]被加一；因此，我们需要高效地更新/查询前缀和
    // 二分查找 + 树状数组：优化对插入位置的查找/更新过程（动态前缀和）
    // https://www.acwing.com/solution/content/9970/
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [&](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];  // k降序
            }
            return a[0] < b[0];  // h升序
        });
        const auto n = (int) people.size();
        int tree[n + 1];  // tree[i] = 1，队列的位置i被占用
        vector<vector<int>> ans(n);
        memset(tree, 0, sizeof tree);
        for (const auto &p: people) {
            auto k = p[1];
            int l = 1; // 二分查找插入位置
            auto r = n;
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (mid - prefixSum(mid, tree) >= k + 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[r - 1] = p;  // 树状数组下标从1开始，这里要减1
            updateItem(r, 1, tree, n);  // 占用位置r，更新tree[r] = 1
        }
        return ans;
    }

private:
    int lowBit(int x) {
        return x & -x;
    }

    void updateItem(int idx, int val, int tree[], int n) {
        for (auto i = idx; i <= n; i += lowBit(i)) {
            tree[i] += val;
        }
    }

    int prefixSum(int idx, const int tree[]) {
        int ans = 0;
        for (auto i = idx; i > 0; i -= lowBit(i)) {
            ans += tree[i];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0406_H
