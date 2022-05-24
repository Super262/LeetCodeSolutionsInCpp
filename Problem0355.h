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
    // 多路归并：大根堆，选择10个时间戳最大的元素
public:
    Twitter() {
        ts = 0; // Current Time
    }

    void postTweet(const int &user_id, const int &tweet_id) {
        tweets[user_id].push_back({ts, tweet_id});
        ++ts;
    }

    vector<int> getNewsFeed(const int &user_id) {
        // 多路归并的重要参数：当前数据项的来源，当前数据项的索引
        followee[user_id].insert(user_id);
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> heap;
        for (const auto &fid: followee[user_id]) {
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

    void follow(const int &follower_id, const int &followee_id) {
        followee[follower_id].insert(followee_id);
    }

    void unfollow(const int &follower_id, const int &followee_id) {
        followee[follower_id].erase(followee_id);
    }

private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followee;
    int ts;
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
