//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0391_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0391_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 扫描线，根据输入构建线段(x,y1,y2)；把线段排序，按横坐标、y轴起点排序
    // 对每个横坐标上的线段执行区间合并（贪心），比较left和right是否匹配
public:
    bool isRectangleCover(const vector<vector<int>> &rectangles) {
        vector<Line> lines;
        lines.reserve(rectangles.size() * 2);
        for (const auto &rect: rectangles) {
            auto x1 = rect[0];
            auto x2 = rect[2];
            auto y1 = rect[1];
            auto y2 = rect[3];
            lines.emplace_back(x1, y1, y2, true);
            lines.emplace_back(x2, y1, y2, false);
        }
        sort(lines.begin(), lines.end());
        const auto n = (int) lines.size();
        for (int st = 0; st < n; ++st) {  // 处理横坐标为x的线段
            auto ed = st;
            while (ed < n && lines[ed].x == lines[st].x) {
                ++ed;
            }
            vector<pair<int, int>> left_segs;
            vector<pair<int, int>> right_segs;
            for (int i = st; i < ed; ++i) {
                if (lines[i].is_left) {  // 按左、右两部分分别合并线段
                    if (!mergeSegs(left_segs, lines[i])) {
                        return false;
                    }
                } else {
                    if (!mergeSegs(right_segs, lines[i])) {
                        return false;
                    }
                }
            }
            if (st > 0 && ed < n) {  // 该区间不包含大矩形的边缘，左、右应完全相等
                if (left_segs != right_segs) {
                    return false;
                }
            } else if (st == 0) {  // 该区间包含大矩形左边界，左边只有1条，右侧为空
                if (left_segs.size() != 1 || !right_segs.empty()) {
                    return false;
                }
            } else {  // 该区间包含大矩形右边界，右边只有1条，左侧为空
                if (!left_segs.empty() || right_segs.size() != 1) {
                    return false;
                }
            }
            st = ed - 1;
        }
        return true;
    }

private:
    struct Line {
        int x;
        int y1;
        int y2;
        bool is_left;

        Line(int x, int y1, int y2, bool is_left) {
            this->x = x;
            this->y1 = y1;
            this->y2 = y2;
            this->is_left = is_left;
        }

        bool operator<(const Line &b) const {
            if (x != b.x) {
                return x < b.x;
            }
            return y1 < b.y1;
        }
    };

    bool mergeSegs(vector<pair<int, int>> &segs, const Line &line) {
        pair<int, int> temp = {line.y1, line.y2};
        if (segs.empty()) {
            segs.emplace_back(temp);
            return true;
        }
        auto &last = segs[segs.size() - 1];
        if (last.second > temp.first) { // 交错
            return false;
        } else if (last.second == temp.first) {  // 首尾可连接
            temp.first = last.first;
            segs.pop_back();
        }
        segs.emplace_back(temp);  // 其他情况
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0391_H
