class Solution {
public:
    int longestIdealString(string str, int k) {
        int n=str.size();
        vector<int>prev(27,0);
        vector<int>curr(27,0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int last=0;last<=26;last++){
                int pick=0,notpick=0;
                notpick = prev[last];
                if(last == 0 || abs(str[idx]-'a'+1 - last) <= k)
                    pick= 1+ prev[str[idx]-'a'+ 1];
                 curr[last] = max(pick , notpick);
            }
            prev=curr;
        }
        return prev[0];
    }
};