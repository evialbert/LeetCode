class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        int length=0,start;
        for(int gap=0;gap<s.size();gap++){
            for(int i=0,j=gap;j<s.size();i++,j++){
                if(gap==0)
                    dp[i][j]=true;
                else if(gap==1){
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==true)
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j]==true){
                    length=gap+1;
                    start=i;
                }
            }
        }
        return s.substr(start,length);
    }
};