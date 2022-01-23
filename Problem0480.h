//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0480_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0480_H

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 2种解法：对顶堆+延迟删除，红黑树（multiset）

class DualHeap {
private:
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int, vector<int>, less<int>> down;
    unordered_map<int, int> delayed;
    int up_size, down_size, k;

    template<class T>
    void Prune(T &heap) {
        while (!heap.empty()) {
            auto num = heap.top();
            if (!delayed.count(num)) {
                return;
            }
            heap.pop();
            --delayed[num];
            if (!delayed[num]) {
                delayed.erase(num);
            }
        }
    }

    void Balance() {
        if (down_size > up_size + 1) {
            up.emplace(down.top());
            down.pop();
            --down_size;
            ++up_size;
            Prune(down);
        } else if (down_size < up_size) {
            down.emplace(up.top());
            up.pop();
            --up_size;
            ++down_size;
            Prune(up);
        }
    }

public:
    DualHeap(int k) {
        up_size = 0;
        down_size = 0;
        this->k = k;
    }

    void Insert(int x) {
        if (down.empty() || x <= down.top()) {
            down.emplace(x);
            ++down_size;
        } else {
            up.emplace(x);
            ++up_size;
        }
        Balance();
    }

    void Erase(int x) {
        ++delayed[x];
        if (x <= down.top()) {
            --down_size;
            Prune(down);
        } else {
            --up_size;
            Prune(up);
        }
        Balance();
    }

    double GetMedian() {
        if (k % 2) {
            return (double) down.top();
        }
        return ((double) down.top() + up.top()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(const vector<int> &nums, int k) {
        DualHeap dh(k);
        vector<double> ans;
        for (int i = 0; i < k; ++i) {
            dh.Insert(nums[i]);
        }
        ans.emplace_back(dh.GetMedian());
        for (int i = k; i < nums.size(); ++i) {
            dh.Insert(nums[i]);
            dh.Erase(nums[i - k]);
            ans.emplace_back(dh.GetMedian());
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0480_H
