//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0705_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0705_H

#include <vector>

using namespace std;

class MyHashSet {
    // 需要删除，选"拉链"法；无需删除，选择开放寻址法
public:
    MyHashSet() {

    }

    void add(int key) {
        auto idx = key % N;
        auto t = find(idx, key);
        if (t == -1) {
            bins[idx].emplace_back(key);
        }
    }

    void remove(int key) {
        auto idx = key % N;
        auto t = find(idx, key);
        if (t != -1) {
            bins[idx].erase(bins[idx].begin() + t);
        }
    }

    bool contains(int key) {
        auto idx = key % N;
        auto t = find(idx, key);
        return t != -1;
    }

private:
    static const int N = 13331;
    vector<int> bins[N];

    int find(int idx, int key) {
        for (int i = 0; i < (int) bins[idx].size(); ++i) {
            if (bins[idx][i] == key) {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0705_H
