class Solution {

    public int maxCount(int m, int n, int[][] ops) {

        if(ops.length==0)return m*n;

        int minX=ops[0][0],minY=ops[0][1];

        for(int i=1;i<ops.length;i++)

        {

                minX=Math.min(minX,ops[i][0]);

                minY=Math.min(minY,ops[i][1]);

        }

        return minX*minY;

    }

}