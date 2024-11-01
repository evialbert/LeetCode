class Solution {
public:
    const int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long>prev(26,0);
        for(auto &ch:s) prev[ch-'a']++;
        while(t--){
            vector<long long>curr(26,0);
            for(int i=0;i<26;i++){
                if(i==25){
                    curr[0]=(curr[0]+prev[25])%mod;
                    curr[1]=(curr[1]+prev[25])%mod;
                }
                else{
                    curr[i+1]=(curr[i+1]+prev[i])%mod;
                }
            }
            swap(curr,prev);
        }
        int result=0;
        for(auto &it:prev){
            result+=it;
            result%=mod;
        }
        return result;
    }
};