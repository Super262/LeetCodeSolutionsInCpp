//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0622_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0622_H

#include <vector>

using namespace std;

class MyCircularQueue {
    // hh表示头部被占用的位置，tt表示尾部尚未被占用的位置；为了区分队满和队空两种情况，我们要求h==t+1表示队满、h==t表示队空
private:
    vector<int> q;
    int hh = 0;
    int tt = 0;

public:
    MyCircularQueue(int k) {
        q.resize(k + 1);  // h==t+1表示队满，所以存储空间为k+1
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[tt] = value;
        tt = (tt + 1) % ((int) q.size());
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        hh = (hh + 1) % ((int) q.size());
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[hh];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        auto t = tt - 1;
        t = (t + (int) q.size()) % ((int) q.size());
        return q[t];
    }

    bool isEmpty() const {
        return hh == tt;
    }

    bool isFull() {
        return (tt + 1) % ((int) q.size()) == hh;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0622_H
