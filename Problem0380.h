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
private:
    unordered_map<int, int> num2Idx;
    vector<int> storage;

public:
    RandomizedSet() {

    }

    bool insert(const int &val) {
        if (num2Idx.count(val)) {
            return false;
        }
        storage.push_back(val);
        num2Idx[val] = (int) storage.size() - 1;
        return true;
    }

    bool remove(const int &val) {
        if (!num2Idx.count(val)) {
            return false;
        }
        auto idx = num2Idx[val];
        auto temp = storage[storage.size() - 1];
        swap(storage[idx], storage[storage.size() - 1]);  // 把带删除的元素放到最后
        num2Idx[temp] = idx;
        num2Idx.erase(val);
        storage.pop_back();
        return true;
    }

    int getRandom() {
        return storage[(random() % storage.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0380_H
