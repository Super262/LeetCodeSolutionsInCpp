
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
public:
    Excel(int height, char width) {
        formulas.resize(height, vector<Formula>((width - 'A') + 1));
    }

    void set(int row, char column, int val) {
        formulas[row - 1][column - 'A'] = Formula(val);
        topoSort(row - 1, column - 'A');
        applyTopo();
    }

    int get(int row, char column) {
        return formulas[row - 1][column - 'A'].value;
    }

    int sum(int row, char column, const vector<string> &numbers) {
        auto cells = getCells(numbers);
        auto sum = updateSum(row - 1, column - 'A', cells);
        set(row, column, sum);
        formulas[row - 1][column - 'A'] = Formula(cells, sum);
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

    void topoSort(int r, int c) {
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

    int updateSum(int r, int c, const unordered_map<string, int> &cells) {
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

    unordered_map<string, int> getCells(const vector<string> &numbers) {
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
