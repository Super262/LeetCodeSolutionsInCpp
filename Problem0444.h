//
// Created by Fengwei Zhang on 5/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0444_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0444_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 拓扑排序：设nums的长度为n，已知所有合法数字属于[1:n]；根据seqs，统计出所有点（数字）的入度并建图（有向边是seq[i]->seq[i+1]）
    // 若存在拓扑排序，则说明图是DAG，可以得到唯一超级序列；若拓扑序列和nums相等，说明nums合法
    // 优化：我们无需实际进行拓扑排序，因为我们只希望确认nums是否合法；我们假设nums合法，记录图中点的前驱关系，检测seqs是否合法
    // 若节点小于1或大于n，节点非法；若某个节点不存在前驱，seqs非法；若发生前驱冲突，seqs非法
public:
    bool sequenceReconstruction(const vector<int> &nums, const vector<vector<int>> &seqs) {
        const auto n = (int) nums.size();
        int ids[n + 1];  // ids[x]：数字x在nums中的索引
        bool existed[n];
        for (int i = 0; i < n; ++i) {
            ids[nums[i]] = i;
        }
        memset(existed, 0, sizeof existed);  // existed[x]：依据seqs，x的前驱是否存在
        for (const auto &s: seqs) {
            int prev_id = -1;  // 前驱的初始值为-1
            for (const auto &x: s) {
                if (x < 1 || x > n) {  // 越界，非法
                    return false;
                }
                auto cur_id = ids[x];
                if (prev_id >= cur_id) {  // 前驱冲突，非法
                    return false;
                }
                if (prev_id + 1 == cur_id) {
                    existed[cur_id] = true;
                }
                prev_id = cur_id;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!existed[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0444_H
