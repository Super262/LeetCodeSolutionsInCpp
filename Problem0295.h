//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0295_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0295_H

#include <queue>

using namespace std;

class MedianFinder { // 对顶堆：两个堆分别维护序列左半部和右半部
public:
    MedianFinder() = default;

    void addNum(const int num) {
        left_part.emplace(num);
        while (left_part.size() > right_part.size()) {
            right_part.emplace(left_part.top());
            left_part.pop();
        }
        while (left_part.size() < right_part.size()) {
            left_part.emplace(right_part.top());
            right_part.pop();
        }
    }

    double findMedian() {
        if (right_part.size() > left_part.size()) {
            return right_part.top();
        }
        if (left_part.size() > right_part.size()) {
            return left_part.top();
        }
        return ((double) left_part.top() + right_part.top()) / 2;
    }

private:
    priority_queue<int, vector<int>, greater<int>> right_part;
    priority_queue<int, vector<int>, less<int>> left_part;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0295_H
