//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0391_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0391_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleCover(const vector<vector<int>> &rectangles) {
        vector<Line> lines;
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
        for (int st = 0; st < n; ++st) {  // 处理[st:ed)内的线段
            auto ed = st;
            while (ed < n && lines[ed].x == lines[st].x) {
                ++ed;
            }
            vector<vector<int>> segsLeft;
            vector<vector<int>> segsRight;
            for (int i = st; i < ed; ++i) {
                if (lines[i].isLeft) {  // 按左、右两部分分别合并线段
                    if (!mergeSegs(segsLeft, lines[i])) {
                        return false;
                    }
                } else {
                    if (!mergeSegs(segsRight, lines[i])) {
                        return false;
                    }
                }
            }
            if (st > 0 && ed < n) {  // 该区间不包含大矩形的边缘
                if (segsRight.size() != segsLeft.size()) {
                    return false;
                }
                const int m = (int) segsLeft.size();
                for (int i = 0; i < m; ++i) {
                    if (segsLeft[i] != segsRight[i]) {
                        return false;
                    }
                }
            } else if (st == 0) {  // 该区间包含大矩形左边界
                if (segsLeft.size() != 1 || !segsRight.empty()) {
                    return false;
                }
            } else {  // 该区间包含大矩形右边界
                if (!segsLeft.empty() || segsRight.size() != 1) {
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
        bool isLeft;

        Line(int x, int y1, int y2, bool isLeft) {
            this->x = x;
            this->y1 = y1;
            this->y2 = y2;
            this->isLeft = isLeft;
        }

        bool operator<(const Line &b) const {
            if (x != b.x) {
                return x < b.x;
            }
            return y1 < b.y1;
        }
    };

    bool mergeSegs(vector<vector<int>> &segs, Line &line) {
        vector<int> temp = {line.y1, line.y2};
        if (segs.empty()) {
            segs.emplace_back(temp);
            return true;
        }
        auto &last = segs[segs.size() - 1];
        if (last[1] > temp[0]) { // 交错
            return false;
        } else if (last[1] == temp[0]) {  // 首位可连接
            temp[0] = last[0];
            segs.pop_back();
        }
        segs.emplace_back(temp);  // 其他情况
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0391_H
