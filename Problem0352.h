//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0352_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0352_H

#include <vector>
#include <set>

using namespace std;

class SummaryRanges {
    // 插入新元素x时，我们查找所有可以和x合并的区间；我们使用set维持区间的有序性；为了简化操作，我们预先插入2个"哨兵"
    // 二分查找到left区间（左端点小于或等于x）和right区间（左端点大于x），分情况讨论
public:
    SummaryRanges() {
        // 预先插入哨兵节点，使得addNum操作中的left和right总是有效值，不报错
        storage.insert({INT_MIN, INT_MIN});
        storage.insert({INT_MAX, INT_MAX});
    }

    void addNum(const int &x) {
        // 查询满足 p.first > x 的p，舍弃所有满足 p.first == x 的p，所以p.second = INT_MAX
        auto it = storage.upper_bound({x, INT_MAX});
        auto right = *it;
        it--;
        auto left = *it;
        if (left.second >= x) {  // 左边已经包括x，无需其他操作
            return;
        }
        if (left.second == x - 1 && right.first == x + 1) { // 左边：[a:x-1]，右边：[x+1:b]；合并左、右和x，生成新区间
            storage.insert({left.first, right.second});
            storage.erase(left);
            storage.erase(right);
            return;
        }
        if (left.second == x - 1) {// 左边：[a:x-1]；合并左和x，生成新区间
            storage.insert({left.first, x});
            storage.erase(left);
            return;
        }
        if (right.first == x + 1) {// 右边：[x+1:b]；合并右和x，生成新区间
            storage.insert({x, right.second});
            storage.erase(right);
            return;
        }
        storage.insert({x, x});
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        res.reserve(storage.size());
        for (auto &p: storage) {
            if (p.first == INT_MIN || p.first == INT_MAX) {
                continue;
            }
            res.push_back({p.first, p.second});
        }
        return res;
    }

private:
    set<pair<int, int>> storage;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0352_H
