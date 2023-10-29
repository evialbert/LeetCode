class Solution {
public:
    int minChanges(string s) {
        int ans = 0, cnt = 0;
        char cur = '1';
        for(int i = 0; i < s.size(); i++){
            if(cnt == 0){
                cur = s[i];
                cnt = 1;
            } else if(s[i] == cur)  cnt++;
            else if(cnt % 2 != 0){
                ans += 1;
                cnt = 0;
            }else { 
                cnt=1;
                 cur=s[i];
            }
        }
        return ans;
    }

};