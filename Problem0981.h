//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0981_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0981_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TimeMap {
    // 哈希表 + 二分查找
public:
    TimeMap() = default;

    void set(const string &key, const string &value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }

    string get(const string &key, int timestamp) {
        const auto &q = data[key];
        pair<int, string> t = {timestamp + 1, ""};
        auto it = upper_bound(q.begin(), q.end(), t);
        if (it == q.begin()) {
            return "";
        }
        it--;
        return it->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0981_H
