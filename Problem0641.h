//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0641_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0641_H

#include <vector>

using namespace std;

class MyCircularDeque {
    // 经典算法，必须掌握：https://www.acwing.com/solution/content/5004/
private:
    int head, tail, size, n;
    vector<int> buffer;

public:
    MyCircularDeque(int k) {
        buffer.resize(k);
        n = k;
        size = 0;
        head = 0;
        tail = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        head = (head + n - 1) % n;  // 相当于head减1
        buffer[head] = value;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        buffer[tail] = value;
        tail = (tail + 1) % n;
        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % n;  // 相当于head加1
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        tail = (tail - 1 + n) % n;  // 相当于tail减1
        --size;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return buffer[head];  // head位置是数据
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return buffer[(tail - 1 + n) % n];  // tail-1位置是数据
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0641_H
