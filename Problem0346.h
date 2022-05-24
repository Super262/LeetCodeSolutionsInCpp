//
// Created by Fengwei Zhang on 5/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0346_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0346_H

#include <deque>

using namespace std;

class MovingAverage {
    // 双端队列
public:
    MovingAverage(int cap) {
        this->capacity = cap;
        this->sum = 0;
    }

    double next(int val) {
        if ((int) q.size() == capacity) {
            sum -= q.front();
            q.pop_front();
        }
        q.emplace_back(val);
        sum += val;
        return (double) sum / (int) q.size();
    }

private:
    int capacity;
    int sum;
    deque<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0346_H
