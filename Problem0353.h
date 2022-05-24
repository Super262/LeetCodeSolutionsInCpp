//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0353_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0353_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class SnakeGame {
    // 双端队列，从后向前保存蛇的坐标（x*width+y）；集合也保存蛇的坐标，用于冲突检测
    // 细节：蛇向前移动时，若头不超出边界，应先删除队尾，再检查头是否和身体相撞
public:
    SnakeGame(int width, int height, vector<vector<int>> &food) {
        score = 0;
        this->width = width;
        this->height = height;
        food_it = food.begin();
        food_end = food.end();
        body_set.insert(0);
        body_seq.emplace_back(0);
        dir["U"] = {-1, 0};
        dir["D"] = {1, 0};
        dir["R"] = {0, 1};
        dir["L"] = {0, -1};
    }

    int move(const string &op) {
        const auto &d = dir[op];
        auto i = body_seq.front();
        auto x = i / width;
        auto y = i % width;
        auto nx = x + d.first;
        auto ny = y + d.second;
        auto ni = nx * width + ny;
        if (nx >= height || ny >= width || nx < 0 || ny < 0) {
            return -1;
        }
        if (food_it != food_end && (*food_it)[0] == nx && (*food_it)[1] == ny) {
            ++score;
            food_it++;
        } else {
            auto t = body_seq.back();
            body_seq.pop_back();
            body_set.erase(t);
        }
        if (body_set.count(ni)) {
            return -1;
        }
        body_seq.emplace_front(ni);  // 最后，检测头是否和身体相撞
        body_set.insert(ni);
        return score;
    }

private:
    int score;
    int width;
    int height;
    vector<vector<int>>::iterator food_it;
    vector<vector<int>>::iterator food_end;
    unordered_set<int> body_set;
    deque<int> body_seq;
    unordered_map<string, pair<int, int>> dir;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0353_H
