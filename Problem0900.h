//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0900_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0900_H

#include <vector>

using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int> &encoding) {
        s = encoding;
        idx = 0;
    }

    int next(int n) {
        while (idx < (int) s.size() && s[idx] < n) {
            n -= s[idx];
            s[idx] = 0;
            idx += 2;
        }
        if (idx >= (int) s.size()) {
            return -1;
        }
        s[idx] -= n;
        return s[idx + 1];
    }

private:
    vector<int> s;
    int idx;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0900_H
