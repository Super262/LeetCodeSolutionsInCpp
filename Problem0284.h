//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0284_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0284_H

#include <vector>

using namespace std;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    // 利用全局变量保存当前值和下个状态
private:
    int current;
    bool has_next;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        has_next = Iterator::hasNext();
        if (has_next) {
            current = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return current;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        auto t = current;
        has_next = Iterator::hasNext();
        if (has_next) {
            current = Iterator::next();
        }
        return t;
    }

    bool hasNext() const {
        return has_next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0284_H
