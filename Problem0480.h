//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0480_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0480_H

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 2种解法：对顶堆+延迟删除，或者采用红黑树（multiset）

class DualHeap {
    // 对顶堆："处在上部的"up为小顶堆，"处在下部的"down是大顶堆；up的元素个数至多和down的元素个数相差1，中位数在2个堆顶间产生
    // 延迟删除：映射delayed[x]=k表示元素x应被删除k次；因此，若堆顶元素变化，我们执行prune操作，删除元素x
private:
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int, vector<int>, less<int>> down;
    unordered_map<int, int> delayed;
    int up_size;
    int down_size;
    int k;

    template<class T>
    void prune(T &heap) {
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

    void balance() {
        if (down_size > up_size + 1) {
            up.emplace(down.top());
            down.pop();
            --down_size;
            ++up_size;
            prune(down);
        } else if (down_size < up_size) {
            down.emplace(up.top());
            up.pop();
            --up_size;
            ++down_size;
            prune(up);
        }
    }

public:
    DualHeap(int k) {
        up_size = 0;
        down_size = 0;
        this->k = k;
    }

    void insert(int x) {
        if (down.empty() || x <= down.top()) {
            down.emplace(x);
            ++down_size;
        } else {
            up.emplace(x);
            ++up_size;
        }
        balance();
    }

    void erase(int x) {
        ++delayed[x];
        if (x <= down.top()) {
            --down_size;
            prune(down);
        } else {
            --up_size;
            prune(up);
        }
        balance();
    }

    double getMedian() {
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
            dh.insert(nums[i]);
        }
        ans.emplace_back(dh.getMedian());
        for (int i = k; i < nums.size(); ++i) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.emplace_back(dh.getMedian());
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0480_H
