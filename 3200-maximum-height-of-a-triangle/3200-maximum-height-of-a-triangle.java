class Solution {

    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(chooseStarting(red, blue), chooseStarting(blue, red));
    }

    private int chooseStarting(int first, int second) {
        int height = 0;
        int row = 1;

        while (true) {
            if (row % 2 == 1) {
                if (first >= row) {
                    first -= row;
                } else {
                    break;
                }
            } else {
                if (second >= row) {
                    second -= row;
                } else {
                    break;
                }
            }
            height++;
            row++;
        }
        return height;
    }
}