//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0281_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0281_H

#include <vector>
#include <queue>

using namespace std;

class ZigzagIterator {
    // 类似k路归并：使用队列依次保存k个向量的候选元素
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        if (!v1.empty()) {
            q.emplace(0, v1);
        }
        if (!v2.empty()) {
            q.emplace(0, v2);
        }
    }

    int next() {
        auto t = q.front();
        q.pop();
        const auto &v = t.second;
        if (t.first + 1 < (int) v.size()) {
            q.emplace(t.first + 1, v);
        }
        return v[t.first];
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    queue<pair<int, const vector<int> &>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0281_H
