class Solution {
    char currentDirection = 'N';
    int x = 0, y = 0;
    public boolean isRobotBounded(String instructions) {
        for (int i = 0; i < instructions.length(); i++) {
            getDirection(instructions.charAt(i));
        }
        
        if (x == 0 && y == 0) {
            return true;
        }
        
        if (currentDirection == 'N') {
            return false;
        }
        
        return true;
    }
    
    public void getDirection(char direction) {
        if (direction == 'G') {
            if (currentDirection == 'N') {
                y = y + 1;
            } else if (currentDirection == 'S') {
                y = y - 1;
            } else if (currentDirection == 'E') {
                x = x + 1;
            } else if (currentDirection == 'W') {
                x = x - 1;
            }
        } else if (direction == 'L') {
            if (currentDirection == 'N') {
                currentDirection = 'W';
            } else if (currentDirection == 'S') {
                currentDirection = 'E';
            } else if (currentDirection == 'E') {
                currentDirection = 'N';
            } else if (currentDirection == 'W') {
                currentDirection = 'S';
            }
        } else {
            if (currentDirection == 'N') {
                currentDirection = 'E';
            } else if (currentDirection == 'S') {
                currentDirection = 'W';
            } else if (currentDirection == 'E') {
                currentDirection = 'S';
            } else if (currentDirection == 'W') {
                currentDirection = 'N';
            }
        }
    }
}