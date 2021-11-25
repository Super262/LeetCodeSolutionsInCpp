//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0381_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0381_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> num2IdxSet;
    vector<int> storage;

public:
    RandomizedCollection() {

    }

    bool insert(const int &val) {
        storage.push_back(val);
        num2IdxSet[val].insert((int) storage.size() - 1);
        return num2IdxSet[val].size() == 1;
    }

    bool remove(const int &x) {
        if (!num2IdxSet.count(x) || num2IdxSet[x].empty()) {
            return false;
        }
        auto px = *(num2IdxSet[x].begin());
        auto py = (int) storage.size() - 1;
        auto y = storage[py];
        swap(storage[px], storage[py]);
        // 注意：对包含x的索引的集合，先执行插入py，再删除py，不能省略任何操作（因为可能 x == y）！
        num2IdxSet[x].erase(px);
        num2IdxSet[x].insert(py);
        num2IdxSet[y].erase(py);
        num2IdxSet[y].insert(px);
        storage.pop_back();
        num2IdxSet[x].erase(py);
        return true;
    }

    int getRandom() {
        return storage[random() % storage.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0381_H
