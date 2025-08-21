
class Solution {
public:
    int minMoves(int startX, int startY, int targetX, int targetY) {
        if (startX == targetX && startY == targetY) return 0;

        queue<pair<int, int>> points;
        points.push({targetX, targetY});

        int moveCount = 0;

        while (!points.empty()) {
            int levelSize = points.size();

            for (int i = 0; i < levelSize; ++i) {
                auto [currX, currY] = points.front();
                points.pop();

                if (currX == startX && currY == startY) return moveCount;

                int nextX = 0, nextY = 0;

                if (currX > currY) {
                    if (currX > 2 * currY) {
                        if (currX % 2 == 0) {
                            nextX = currX / 2;
                            nextY = currY;
                            if (nextX >= startX) {
                                points.push({nextX, nextY});
                            }
                        }
                    } else {
                        nextX = currX - currY;
                        nextY = currY;
                        if (nextX >= startX) {
                            points.push({nextX, nextY});
                        }
                    }
                } else if (currY > currX) {
                    if (currY > 2 * currX) {
                        if (currY % 2 == 0) {
                            nextX = currX;
                            nextY = currY / 2;
                            if (nextY >= startY) {
                                points.push({nextX, nextY});
                            }
                        }
                    } else {
                        nextX = currX;
                        nextY = currY - currX;
                        if (nextY >= startY) {
                            points.push({nextX, nextY});
                        }
                    }
                } else {  // currX == currY
                    if (startX == 0) {
                        points.push({0, currY});
                    }
                    if (startY == 0) {
                        points.push({currX, 0});
                    }
                }
            }
            moveCount++;
        }

        return -1;
    }
};
