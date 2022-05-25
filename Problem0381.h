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
    // 数组 + 哈希表（数字-索引集合）：获取随机数时，生成随机索引i，返回数组中索引i对应的数字
    // 插入新元素x时，将x追加到数组末尾，哈希表记录x的索引；
    // 删除元素y时，将y和数组尾部元素x交换，更新x、y的索引集合，最后从哈希表上删除y、弹出数字尾部，并再次更新x的索引集合
public:
    RandomizedCollection() = default;

    bool insert(const int &val) {
        storage.emplace_back(val);
        num_idx_set[val].insert((int) storage.size() - 1);
        return num_idx_set[val].size() == 1;
    }

    bool remove(const int &x) {
        if (!num_idx_set.count(x)) {
            return false;
        }
        auto px = *(num_idx_set[x].begin());
        auto py = (int) storage.size() - 1;
        auto y = storage[py];
        swap(storage[px], storage[py]);
        // 注意：对包含x的索引的集合，先执行插入py，再删除py，不能省略任何操作（因为可能 x == y）！
        num_idx_set[x].erase(px);
        num_idx_set[x].insert(py);
        num_idx_set[y].erase(py);
        num_idx_set[y].insert(px);
        storage.pop_back();
        num_idx_set[x].erase(py);
        if (num_idx_set[x].empty()) {
            num_idx_set.erase(x);
        }
        return true;
    }

    int getRandom() {
        return storage[random() % storage.size()];
    }

private:
    unordered_map<int, unordered_set<int>> num_idx_set;
    vector<int> storage;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0381_H
