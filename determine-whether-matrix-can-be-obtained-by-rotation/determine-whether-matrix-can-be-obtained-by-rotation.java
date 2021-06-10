class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        if(equals(mat, target)) {
            return true;
        }
        return rotate(mat, target, 1) || rotate(mat, target, 2) || rotate(mat, target, 3);
    }
    
    private boolean rotate(int[][] mat, int[][] target, int times) {
        int n = mat.length;
        if (times == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mat[n-j-1][i] != target[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        } else if (times == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mat[n-i-1][n-j-1] != target[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mat[j][n-i-1] != target[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    
    private boolean equals(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}