class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n=s.size();
        vector<int> leftMost(26,-1), rightMost(26,-1);
        for(int i=0;i<n;++i){
            int ch = s[i]-'a';
            if(leftMost[ch]==-1) leftMost[ch]=i;
            rightMost[ch]=i;
        }
        
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;--i){
            dp[i]=dp[i+1]; 
            int ch = s[i]-'a';
            if(leftMost[ch]!=i) continue;

            bool valid=true;
            int maxExpand = rightMost[ch];
            for(int j=i+1;j<maxExpand;++j){
                int ch1= s[j]-'a';
                if(leftMost[ch1] < i){
                    valid=false;
                    break;
                }
                if(rightMost[ch1] > maxExpand) maxExpand = rightMost[ch1];
            }

            if(valid && (i!=0 || maxExpand !=n-1)) dp[i]=max(dp[i],1+dp[maxExpand+1]);
        }

        return dp[0]>=k;
    }
};