//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0818_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0818_H

#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典的BFS剪枝，直接背诵！牢记自定义结构体的哈希语法！
    // https://www.acwing.com/solution/content/927/
public:
    int racecar(const int target) {
        queue<Node> q;
        unordered_map<Node, int, node_hash> dist;
        Node st_node(0, 0, true);
        q.push(st_node);
        dist[st_node] = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.pos == target) {
                return dist[t];
            }
            Node ne_a(t.pos + (t.dir ? 1 : -1) * (1 << t.spd), t.spd + 1, t.dir);  // 操作A后的状态
            if (ne_a.pos >= 0 && ne_a.pos <= (target << 1) && (!dist.count(ne_a) || dist[ne_a] > dist[t] + 1)) {
                q.emplace(ne_a);
                dist[ne_a] = dist[t] + 1;
            }
            Node ne_r(t.pos, 0, !t.dir);  // 操作R后的状态
            if (ne_r.pos >= 0 && ne_r.pos <= (target << 1) && (!dist.count(ne_r) || dist[ne_r] > dist[t] + 1)) {
                q.emplace(ne_r);
                dist[ne_r] = dist[t] + 1;
            }
        }
        return -1;
    }

private:
    struct Node {
        int pos, spd;  // 位置、速度(2^spd)
        bool dir;  // 方向

        Node(int pos, int spd, bool dir) {
            this->pos = pos;
            this->spd = spd;
            this->dir = dir;
        }

        // `operator==` is required to compare keys in case of a hash collision
        bool operator==(const Node &node) const {
            return pos == node.pos && spd == node.spd && dir == node.dir;
        }
    };

    struct node_hash {  // The specialized hash function for `unordered_map` keys
        std::size_t operator()(const Node &node) const {
            return node.pos * 5849 + node.spd * 131 + node.dir * 23;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0818_H
