//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0295_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0295_H

#include <queue>

using namespace std;

class MedianFinder { // 对顶堆：两个堆分别维护序列左半部和右半部
private:
    priority_queue<int, vector<int>, greater<int>> rightPart;
    priority_queue<int, vector<int>, less<int>> leftPart;

public:
    MedianFinder() {

    }

    void addNum(const int num) {
        leftPart.emplace(num);
        while (leftPart.size() > rightPart.size()) {
            rightPart.emplace(leftPart.top());
            leftPart.pop();
        }
        while (leftPart.size() < rightPart.size()) {
            leftPart.emplace(rightPart.top());
            rightPart.pop();
        }
    }

    double findMedian() {
        if (rightPart.size() > leftPart.size()) {
            return rightPart.top();
        }
        if (leftPart.size() > rightPart.size()) {
            return leftPart.top();
        }
        return ((double) leftPart.top() + rightPart.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0295_H
