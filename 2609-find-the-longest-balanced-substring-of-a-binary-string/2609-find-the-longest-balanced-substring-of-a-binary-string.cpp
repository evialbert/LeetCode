class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        int zeros = 0;
        int ones=0;
        for(int i=0;i<s.length();i++){
            
            
            if(s[i]=='0') zeros++;
            if(s[i]=='1'){ ones++;}
            
            if(ones>=zeros){
                ans = max(ans,zeros*2);
            }
            if(zeros>=ones){
                ans = max(ans,ones*2);
            }
            
            if(s[i]=='1' && s[i+1]=='0') {
                             zeros=0;
                             ones=0;
                         }
            
        }
        
        return ans;
    }
};