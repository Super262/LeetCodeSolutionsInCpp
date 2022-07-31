//
// Created by Fengwei Zhang on 3/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0780_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0780_H

class Problem0780 {
    // 试图从点(sx,sy)向点(tx,ty)进行转换十分不便，因为我们不确定要进行哪种转换；因此，我们可以逆向操作，逆向转换总是确定的
    // 例如，当前为(tx,ty)，上步为(tx-ty,ty)或(tx,ty-tx)；但是，数据范围很大(10^9)，我们不能使用简单的减法
    // 根据题意，sx和sy是正数；假设从(sx,sy)到(tx,ty)只经历了一种变换，那么tx=sx+k*sy或ty=sy+k*sx；因此，我们用取余替代减法
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) {
                break;
            }
            if (tx > ty) {
                if (ty > sy) {
                    tx %= ty;
                } else {
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (tx > sx) {
                    ty %= tx;
                } else {
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return sx == tx && sy == ty;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0780_H
