class Solution {
            public int[] getBiggestThree(int[][] grid) {
        int x = grid.length-1, y = grid[0].length-1;
        int[] res = new int[3];
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                int left = Math.min(x, j);
                int right = Math.min(x, y-j);
                int down = (x-i)/2;
                int radius = Math.min(Math.min(left, down), right);
                fillTop(res, grid[i][j]);
                for(int k=1; k<=radius; k++){
                    findRadius(grid, k, i, j, res);
                }

            }
        }
        if(res[2]>0){
            return res;
        } if(res[1]>0){
            return new int[]{res[0], res[1]};
        } else {
            return new int[]{res[0]};
        }
    }

    private void findRadius(int[][] grid, int k, int i, int j, int[] res) {
        int b = 2*(k);
        int leftSum = 0, rightSum=0, leftbtm=0, rightbtm=0, up = grid[i][j], down = grid[b+i][j];
        for(int m=1; m<=k; m++){
            leftSum = leftSum + grid[i+m][j-m];
            rightSum = rightSum + grid[i+m][j+m];
            if(i+m != (b+i)-m) {
                leftbtm = leftbtm + grid[b+i - m][j - m];
            }
            if(i+m!=b+i-m) {
                rightbtm = rightbtm + grid[b+i - m][j + m];
            }
        }
        int sum = leftSum+rightSum+leftbtm+rightbtm+up+down;
        fillTop(res, sum);
    }

    private void fillTop(int[] res, int val) {
        if(val!=res[0] && val!=res[1] && val!=res[2] && val>res[0]){
            res[2] = res[1];
            res[1] = res[0];
            res[0] = val;
        } else if(val!=res[0] && val!=res[1] && val!=res[2] && val>res[1]){
            res[2] = res[1];
            res[1] = val;
        } else if(val!=res[0] && val!=res[1] && val!=res[2] && val>res[2]){
            res[2] = val;
        }
    }
}