//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0632_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0632_H

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    // K路归并算法，利用小根堆维护这K个序列的最小值minimal，维护全局变量记录堆内元素的最大值maximal，最终答案为(minimal,maximal)
public:
    vector<int> smallestRange(const vector<vector<int>> &nums) {
        const int INF = 0x3f3f3f3f;
        priority_queue<Node, vector<Node>, greater<Node>> heap;
        auto maximal = -INF;
        for (int i = 0; i < (int) nums.size(); ++i) {
            heap.push({nums[i][0], i, 0});
            maximal = max(maximal, nums[i][0]);
        }
        vector<int> ans = {-INF, INF};
        while (!heap.empty()) {
            const auto t = heap.top();
            heap.pop();
            auto l = t.value;
            if (maximal - l < ans[1] - ans[0]) {  // 发现更优的解
                ans[1] = maximal;
                ans[0] = l;
            }
            auto i = t.i;
            auto j = t.j;
            if (j + 1 >= (int) nums[i].size()) {  // 已经处理完所有公共部分，终止
                return ans;
            }
            heap.push({nums[i][j + 1], i, j + 1});
            maximal = max(maximal, nums[i][j + 1]);
        }
        return ans;
    }

private:
    struct Node {
        int value;
        int i;  // value在数组中的索引
        int j;  // 数组nums[i]在nums中的索引

        bool operator>(const Node &b) const {  // 对应小根堆
            return this->value > b.value;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0632_H
