//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1025_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1025_H

class Problem1025 {
    // 结论：奇数必败，偶数必胜（必胜态：后继状态中至少一个是必败态；必败态：后继状态无必败态）
    // n=1，结论成立；设k<n时，结论成立，要证k=n时，结论也成立
    // (1) k为奇数，若x被选中（x可整除k），则x也是奇数，那么(k-x)是偶数，k必败
    // (2) k为偶数，显然k-1必败，因此k必胜
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1025_H
