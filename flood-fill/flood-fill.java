class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int oColor = image[sr][sc];
        if (oColor == newColor) {
            return image;
        }
        int[][] dir = new int[][]{{0, 1},{0, -1},{1, 0},{-1, 0}};
        image[sr][sc] = newColor;
        for (int i = 0; i < dir.length; i ++) {
            int nextX = sr + dir[i][0];
            int nextY = sc + dir[i][1];
            if (nextX < 0 || nextX >= image.length || nextY < 0 || nextY >= image[0].length) {
                continue;
            }
            if (image[nextX][nextY] != oColor) {
                continue;
            }
            floodFill(image, nextX, nextY, newColor);
        }
        return image;
    }
}