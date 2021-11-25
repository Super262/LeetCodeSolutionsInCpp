//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0355_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0355_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followee;
    int ts;

public:
    Twitter() {
        ts = 0; // Current Time
    }

    void postTweet(const int &userId, const int &tweetId) {
        tweets[userId].push_back({ts, tweetId});
        ++ts;
    }

    vector<int> getNewsFeed(const int &userId) {
        // 多路归并的重要参数：当前数据项的来源，当前数据项的索引
        followee[userId].insert(userId);
        priority_queue<vector<int>> heap;
        for (const auto &fid: followee[userId]) {
            auto &messages = tweets[fid];
            if (messages.empty()) {
                continue;
            }
            auto tid = (int) messages.size() - 1;
            heap.push({messages[tid].first, messages[tid].second, fid, tid});
        }
        vector<int> res;
        for (int i = 0; i < 10 && !heap.empty(); ++i) {
            auto t = heap.top();
            heap.pop();
            res.push_back(t[1]);
            auto fid = t[2];
            auto tid = t[3];
            if (tid == 0) {
                continue;
            }
            auto &messages = tweets[fid];
            heap.push({messages[tid - 1].first, messages[tid - 1].second, fid, tid - 1});
        }
        return res;
    }

    void follow(const int &followerId, const int &followeeId) {
        followee[followerId].insert(followeeId);
    }

    void unfollow(const int &followerId, const int &followeeId) {
        followee[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0355_H
