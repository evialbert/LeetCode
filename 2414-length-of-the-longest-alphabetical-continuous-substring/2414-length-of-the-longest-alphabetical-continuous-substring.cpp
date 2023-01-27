class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int count = 1;
        int n = s.size();
        for(int i=1;i<n;i++){
            if((s[i-1]-'a')+1==(s[i]-'a')){
                count++;
            } else{
                ans = max(ans,count);
                count =1;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};