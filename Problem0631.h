
//
// Created by Fengwei Zhang on 6/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0631_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0631_H

#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Excel {
    // 拓扑排序，若A1=sum("A2:B4")，说明A1依赖于A2～B4间所有格子
    // 我们引入Formula类型：value表示当前格子的数值，cells表示当前格子所依赖的其他格子，即当前格子的前驱
    // 当格子(r,c)的值被改变（set函数）后，我们先清除(r,c)的旧前驱，保存新值，再通过拓扑排序搜索到所有依赖于(r,c)的格子，并依据拓扑顺序更新它们的值
    // 当格子(r,c)的公式被改变（sum函数）后，我们先根据新公式计算出(r,c)的新值sum，更新所有依赖于(r,c)的格子，再保存(r,c)的新前驱
public:
    Excel(int height, char width) {
        formulas.resize(height, vector<Formula>((width - 'A') + 1));
    }

    void set(int row, char column, int val) {
        formulas[row - 1][column - 'A'] = Formula(val);  // 清除旧前驱，保存新值
        topoSort(row - 1, column - 'A');  // 搜索以(row,column)为起点的拓扑序列
        applyTopo();  // 依据拓扑顺序更新
    }

    int get(int row, char column) {
        return formulas[row - 1][column - 'A'].value;
    }

    int sum(int row, char column, const vector<string> &numbers) {
        auto cells = getCells(numbers);  // 解析出新前驱cells
        auto sum = updateSum(row - 1, column - 'A', cells);  // 获取新值sum
        set(row, column, sum);  // 应用新值
        formulas[row - 1][column - 'A'] = Formula(cells, sum);  // 保存新前驱cells和新值sum
        return sum;
    }

private:
    struct Formula {
        unordered_map<string, int> cells;
        int value;

        Formula() {
            value = 0;
        }

        Formula(int value) {
            this->value = value;
        }

        Formula(const unordered_map<string, int> &cells, int value) {
            this->cells = cells;
            this->value = value;
        }
    };

    vector<vector<Formula>> formulas;
    stack<pair<int, int>> stk;

    void topoSort(int r, int c) {  // DFS实现拓扑排序，代码更少
        const auto key = string(1, (char) (c + 'A')) + to_string(r + 1);
        for (int i = 0; i < (int) formulas.size(); ++i) {
            for (int j = 0; j < (int) formulas[i].size(); ++j) {
                if (!formulas[i][j].cells.count(key)) {
                    continue;
                }
                topoSort(i, j);
            }
        }
        stk.emplace(r, c);
    }

    void applyTopo() {
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            if (formulas[t.first][t.second].cells.empty()) {
                continue;
            }
            updateSum(t.first, t.second, formulas[t.first][t.second].cells);
        }
    }

    int updateSum(int r, int c, const unordered_map<string, int> &cells) {  // 更新格子(r,c)的值为其前驱的值的和
        int sum = 0;
        for (const auto &it: cells) {
            const auto &key = it.first;
            auto x = stoi(key.substr(1)) - 1;
            auto y = key[0] - 'A';
            sum += formulas[x][y].value * it.second;
        }
        formulas[r][c] = Formula(cells, sum);
        return sum;
    }

    unordered_map<string, int> getCells(const vector<string> &numbers) {  // 从公式解析出每个格子
        unordered_map<string, int> cells;
        for (const auto &s: numbers) {
            auto t = s.find(':');
            if (t == string::npos) {
                cells[s]++;
                continue;
            }
            auto st = s.substr(0, t);
            auto ed = s.substr(t + 1);
            auto sj = st[0];
            auto ej = ed[0];
            auto si = stoi(st.substr(1));
            auto ei = stoi(ed.substr(1));
            for (auto i = si; i <= ei; ++i) {
                for (auto j = sj; j <= ej; ++j) {
                    auto key = string(1, j) + to_string(i);
                    cells[key]++;
                }
            }
        }
        return cells;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0631_H
