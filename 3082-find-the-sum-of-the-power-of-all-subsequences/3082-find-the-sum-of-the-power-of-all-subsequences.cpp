class Solution {
public:
    long long  mod =(1e9+7) ;
    int dp[101][102][101] ;
    long long  cal(int i ,vector<int>&nums, int n ,int k ,int c )
    {
        if(k<0)
            return 0 ;
        
        if(k==0)
        {
            long long  x = 1; 
            for(int j= 0; j<n-c; j++ )
            {
                x*=2; 
                x%=mod;
            }
            return x%mod; 
        }
        if(i==n)
        {
                    if(k==0)
        {
                       long long  x = 1; 
            for(int j= 0; j<n-c; j++ )
            {
                x*=2; 
                x%=mod;
            }
            return x%mod;
        }
            else
                return 0 ; 
        }
        if(dp[i][k][c]!=-1)
            return dp[i][k][c]; 
        
        long long  a = 0, b=0 ; 
        a = cal(i+1, nums, n , k- nums[i], c+1) ;
        b = cal(i+1, nums, n ,k ,c ) ;
        
        return dp[i][k][c] = (a+b)%mod; 
    }
    int sumOfPower(vector<int>& nums, int k) {
     
        int n =nums.size() ;
        memset(dp, -1, sizeof(dp)); 
      return  cal(0 ,nums, n ,k , 0 ) ;
        
        
    }
};