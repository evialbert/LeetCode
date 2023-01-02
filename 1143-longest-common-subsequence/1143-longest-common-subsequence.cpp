class Solution {
public:
    int LCS(string X, string Y,int m,int n)
    {
        int t[m+1][n+1];   //matrix

        for(int i=0;i<m+1;i++)
        {
            for(int j =0;j<n+1;j++)
            {
                if(i==0 || j==0)    //base condition
                {
                    t[i][j] = 0;
                }
                else if(X[i-1] == Y[j-1])    //check if last element is equal or not
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else   //otherwise Find Max btw the remaining
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[m][n];    //return the ans
    }

    int longestCommonSubsequence(string X, string Y) {
        int m = X.size();
        int n = Y.size();

        return LCS(X,Y,m,n);
        
    }
};