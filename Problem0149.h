//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0149_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0149_H

#include <vector>

using namespace std;

class Problem0149 {
public:
    int maxPoints(const vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        int result = 1;
        for (int i = 0; i < (int) points.size(); ++i) {
            unordered_map<long double, int> slopeLine;  // 指定斜率的直线覆盖的点的数量
            int duplicateCnt = 0;  // 与points[i]重合的点的数量
            int verticalLine = 1;  // 垂直于x轴的直线覆盖的点的数量
            for (int j = i + 1; j < (int) points.size(); ++j) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    ++duplicateCnt;
                } else if (points[j][0] == points[i][0]) {
                    ++verticalLine;
                }
            }
            for (int j = i + 1; j < (int) points.size(); ++j) {
                if (points[j][0] == points[i][0]) {
                    continue;
                }
                auto sl = (long double) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                if (slopeLine.count(sl)) {
                    ++slopeLine[sl];
                } else {
                    slopeLine[sl] = 2;
                }
                result = max(result, slopeLine[sl] + duplicateCnt);
            }
            result = max(result, verticalLine);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0149_H
