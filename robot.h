//
// Created by Fengwei Zhang on 6/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_ROBOT_H
#define LEETCODESOLUTIONSINCPP_ROBOT_H

class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();

    void turnRight();

    // Clean the current cell.
    void clean();
};

#endif //LEETCODESOLUTIONSINCPP_ROBOT_H
