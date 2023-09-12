class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        unordered_map<int,char> mp;
        int cnt=1;
        int res=0;
        for(int i=1;i<=s.size();i++){
            if(i<s.size() && s[i]==s[i-1]){
                cnt++;
            }
            else if(mp.find(cnt)==mp.end()){
                mp[cnt]=s[i-1];
                cnt=1;
            }
            else{
                while(mp.find(cnt)!=mp.end() && cnt>=0){
                    cnt--;
                    res++;
                }
                if(cnt!=0) mp[cnt]=s[i-1];
                cnt=1;
            }
        }
        return res;
    }
};