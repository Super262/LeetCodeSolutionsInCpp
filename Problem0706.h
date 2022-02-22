//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0706_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0706_H

#include <vector>

using namespace std;

class MyHashMap {
public:
    MyHashMap() {

    }

    void put(int key, int value) {
        auto idx = key % N;
        auto t = find(idx, key);
        if (t == -1) {
            bins[idx].emplace_back(key, value);
        } else {
            bins[idx][t].second = value;
        }
    }

    int get(int key) {
        auto idx = key % N;
        auto t = find(idx, key);
        if (t == -1) {
            return -1;
        }
        return bins[idx][t].second;
    }

    void remove(int key) {
        auto idx = key % N;
        auto t = find(idx, key);
        if (t == -1) {
            return;
        }
        bins[idx].erase(bins[idx].begin() + t);
    }

private:
    static const int N = 13331;
    vector<pair<int, int>> bins[N];

    int find(int idx, int key) {
        for (int i = 0; i < bins[idx].size(); ++i) {
            if (bins[idx][i].first == key) {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0706_H
