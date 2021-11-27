//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0406_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0406_H

#include <vector>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/9970/
    // 贪心思想排序，直接背诵：h升序，k降序；依次恢复队列，当前尚未被填充的位置的身高h' >= h
    // 二分查找 + 树状数组：优化对插入位置的查找过程
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        const int n = (int) people.size();
        vector<int> tree(n + 1, 0);  // tree[i] = 1，位置i被占用
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];  // k降序
            }
            return a[0] < b[0];  // h升序
        });
        vector<vector<int>> res(n);
        for (const auto &p: people) {
            auto h = p[0];
            auto k = p[1];
            int l = 1; // 二分查找插入位置
            int r = n;
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (mid - prefixSum(mid, tree) >= k + 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            res[r - 1] = p;  // 树状数组下表从1开始，这里要减1
            updateItem(r, 1, tree, n);  // 占用位置r，更新tree[r] = 1
        }
        return res;
    }

private:
    int lowBit(int x) {
        return x & -x;
    }

    void updateItem(int idx, int val, vector<int> &tree, int n) {
        for (int i = idx; i <= n; i += lowBit(i)) {
            tree[i] += val;
        }
    }

    int prefixSum(int idx, vector<int> &tree) {
        int res = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            res += tree[i];
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0406_H
