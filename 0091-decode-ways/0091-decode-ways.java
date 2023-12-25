class Solution {
    public int numDecodings(String s) {
        int l=s.length();
        char ch[]=s.toCharArray();
        if(ch[0]=='0')
            return 0;
        int i,flag=0;
        int dp[]=new int[l];
        dp[0]=1;
        for(i=1;i<l;i++)
        {
            if(ch[i]=='0')
            { 
                // '0' can be combined with only '1' or '2' else a decoded way will not exist
                if(ch[i-1]=='0' || ch[i-1]>'2')
                {
                    flag=1;
                    break;
                }
                if(i==1)
                    dp[i]++;
                else
                    dp[i]=dp[i-2];
            }
            else
            {
                dp[i]=dp[i-1];
                if((ch[i-1]=='2' && ch[i]<'7') || ch[i-1]=='1')
                    {
                    if(i==1)
                        dp[i]++;
                        else
                            dp[i]+=dp[i-2];
                  
                     }
            }
        }
         if(flag==1)
              {
                  return 0;
                }
              return dp[l-1];
    }
        
}