//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0295_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0295_H

#include <queue>

using namespace std;

class MedianFinder {
    // 巧妙方法：两个堆分别维护现有升序序列的左半部和右半部，输入数据先进左堆，两堆长度的差值最大为1
    // 细节：序列长度的奇偶性会影响中位数的计算
public:
    MedianFinder() = default;

    void addNum(const int num) {
        left_heap.emplace(num);
        while (left_heap.size() > right_heap.size()) {
            right_heap.emplace(left_heap.top());
            left_heap.pop();
        }
        while (left_heap.size() < right_heap.size()) {
            left_heap.emplace(right_heap.top());
            right_heap.pop();
        }
    }

    double findMedian() {
        if (right_heap.size() > left_heap.size()) {
            return right_heap.top();
        }
        if (left_heap.size() > right_heap.size()) {
            return left_heap.top();
        }
        return ((double) left_heap.top() + right_heap.top()) / 2;
    }

private:
    priority_queue<int, vector<int>, greater<int>> right_heap;
    priority_queue<int, vector<int>, less<int>> left_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0295_H
