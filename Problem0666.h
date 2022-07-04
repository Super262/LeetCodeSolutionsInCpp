//
// Created by Fengwei Zhang on 7/4/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0666_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0666_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 模拟层序遍历，发现叶节点时累加路径和到答案ans；cur指示下个被处理的数是nums[cur]，level是待处理节点的层号（从1开始）
    // 若当前节点node有子节点，即存在层内索引（从0开始）为node.idx*2或node.idx*2+1的节点，则继续遍历；否则，累加路径和到答案
public:
    int pathSum(const vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        queue<pair<int, int>> q;
        int cur = 0;
        int ans = 0;
        int level = 1;
        q.emplace(nums[cur] % 100 / 10 - 1, nums[cur] % 10);
        ++level;
        ++cur;
        while (!q.empty()) {
            for (int k = (int) q.size(); k > 0; --k) {
                auto node = q.front();
                q.pop();
                bool is_leaf = true;
                while (cur < (int) nums.size() && nums[cur] / 100 == level) {
                    auto idx = nums[cur] % 100 / 10 - 1;
                    if (idx != node.first * 2 && idx != node.first * 2 + 1) {
                        break;
                    }
                    is_leaf = false;
                    q.emplace(idx, node.second + nums[cur] % 10);
                    ++cur;
                }
                if (is_leaf) {
                    ans += node.second;
                }
            }
            ++level;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0666_H
