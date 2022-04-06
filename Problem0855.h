
//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0855_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0855_H

#include <set>

using namespace std;

class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        int p = 0;
        if (s.empty()) {
            s.insert(p);
            return p;
        }
        auto dist = *s.begin() - p;  // 距离的初始值
        for (auto i = s.begin(); i != s.end(); i++) {  // 枚举每个区间[i:j]，i、j是被占用的座位
            auto j = i;
            j++;
            if (j == s.end()) {
                if (dist < n - 1 - *i) {
                    dist = n - 1 - *i;
                    p = n - 1;
                }
            } else {
                if (dist < (*j - *i) / 2) {
                    dist = (*j - *i) / 2;
                    p = *i + dist;
                }
            }
        }
        s.insert(p);
        return p;
    }

    void leave(int p) {
        s.erase(p);
    }

private:
    int n;
    set<int> s;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0855_H
