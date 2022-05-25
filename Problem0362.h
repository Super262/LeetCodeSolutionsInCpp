//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0362_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0362_H

#include <deque>
#include <queue>

using namespace std;

class HitCounter {
    // 应对follow-up问题（同时间戳有多个hits）：仍然是队列实现，队列保存(ts,cnt)
    // ts是时刻，cnt表示ts时刻的命中次数；全局变量total记录命中次数的累加和
public:
    HitCounter() {
        this->total = 0;
    }

    void hit(int timestamp) {
        if (this->hits.empty() || this->hits.back().first != timestamp) {
            // Insert the new timestamp with count = 1
            this->hits.emplace(timestamp, 1);
        } else {
            // Update the count of latest timestamp by incrementing the count by 1
            ++this->hits.back().second;
        }
        ++this->total;
    }

    int getHits(int timestamp) {
        while (!this->hits.empty() && timestamp - this->hits.front().first >= K) {
            // Decrement total by the count of the oldest timestamp
            this->total -= this->hits.front().second;
            this->hits.pop();
        }
        return this->total;
    }

private:
    const int K = 300;
    int total;
    queue<pair<int, int> > hits;
};

/*
class HitCounter {
    // 队列实现最大长度为K的滑动窗口
public:
    HitCounter() = default;

    void hit(int timestamp) {
        q.emplace(timestamp);
    }

    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= K) {
            q.pop();
        }
        return (int) q.size();
    }

private:
    const int K = 300;
    queue<int> q;
};
*/

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0362_H
