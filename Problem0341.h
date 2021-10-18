//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0341_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0341_H

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <vector>
#include <queue>

using namespace std;

class NestedIterator {
private:
    queue<int> data;

    void flatten(const vector<NestedInteger> &nestedList) {
        for (const auto &ni: nestedList) {
            if (ni.isInteger()) {
                data.emplace(ni.getInteger());
            } else {
                flatten(ni.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        auto t = data.front();
        data.pop();
        return t;
    }

    bool hasNext() {
        return !data.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0341_H
