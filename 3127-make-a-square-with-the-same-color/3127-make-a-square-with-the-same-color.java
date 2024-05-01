class Solution {
    public boolean canMakeSquare(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m-1; j++) {
                int countBlack = 0;
                int countWhite = 0;
                for(int k = i; k <= i+1; k++) {
                    for(int l = j; l <= j+1; l++) {
                        if(grid[k][l] == 'W') countWhite++;
                        else countBlack++;
                    }
                }
                if(countBlack >= 3 || countWhite >= 3) return true;
            }
        }

        return false;
    }
}