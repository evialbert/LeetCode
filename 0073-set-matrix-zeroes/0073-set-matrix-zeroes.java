class Solution {
    public void setZeroes(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;

        int row[] = new int[n];
        int col[] = new int[m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if( arr[i][j] ==0 )
                {
                   row[i]=1;
                   col[j]=1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if( row[i]==1 )
            {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            if( col[j]==1 )
            {
                for (int i = 0; i < n; i++) {
                    arr[i][j] = 0 ;
                }
            }
        }
    }
}