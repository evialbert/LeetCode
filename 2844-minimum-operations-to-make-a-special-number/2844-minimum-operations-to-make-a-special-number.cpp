class Solution {
public:
    int minimumOperations(string num) {
       vector <int> dp(num.size()+1,0);
      
      for(int i=1;i<=num.size();i++)
      {    dp[i] = dp[i-1]+1;
           if(num[i-1]=='0')
            dp[i] = i-1;
          for(int j=i-1;j>=1;j--)
          {  
             if(num[i-1]=='5' && (num[j-1]=='7' || num[j-1]=='2'))
              dp[i] = min(dp[i],i-j-1);
             else if(num[i-1]=='0' && (num[j-1]=='0' || num[j-1]=='5'))
              dp[i] = min(dp[i],i-j-1);
          }
         
      }

      return dp[num.size()];
   }
};