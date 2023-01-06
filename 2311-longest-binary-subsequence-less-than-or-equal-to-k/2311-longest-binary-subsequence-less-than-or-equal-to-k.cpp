class Solution {
public:
    int longestSubsequence(string s, int k) {
        int mx=0;
        for(int i=0;i<s.size();++i){
            long long cur=0;
            int cnt=0;
            for(int j=i;j<s.size();++j){
                if(s[j]=='1')
                    ++cur;
                if(cur<=k){
                    mx=max(mx,j-i+1-cnt);
                }
                else{
                    turn_of(cur);
                    ++cnt;
                }
                cur<<=1;
            }
        }
        return mx;
    }
    void turn_of(long long &num){
        for(int bt=62;bt>=0;--bt){
            if((1LL<<bt)&num){
                num&=~(1<<bt);
                return;
            }
        }
    }
    
};