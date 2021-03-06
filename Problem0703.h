//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0703_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0703_H

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(const int k, const vector<int> &nums) {
        limit = k;
        for (const auto &x: nums) {
            add(x);
        }
    }

    int add(const int val) {
        heap.emplace(val);
        if (heap.size() > limit) {
            heap.pop();
        }
        return heap.top();
    }

private:
    int limit;
    priority_queue<int, vector<int>, greater<int>> heap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0703_H
