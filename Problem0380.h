//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0380_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0380_H

#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(const int &val) {
        if (num_idx.count(val)) {
            return false;
        }
        storage.push_back(val);
        num_idx[val] = (int) storage.size() - 1;
        return true;
    }

    bool remove(const int &val) {
        if (!num_idx.count(val)) {
            return false;
        }
        auto idx = num_idx[val];
        auto temp = storage[storage.size() - 1];
        swap(storage[idx], storage[storage.size() - 1]);  // 把带删除的元素放到最后
        num_idx[temp] = idx;
        num_idx.erase(val);
        storage.pop_back();
        return true;
    }

    int getRandom() {
        return storage[(random() % storage.size())];
    }

private:
    unordered_map<int, int> num_idx;
    vector<int> storage;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0380_H
