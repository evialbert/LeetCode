class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        long long eoo=0;
        long long eto=0;
        long long eoe=0;
        long long ete=0;
        const int MOD=1e9+7;
        for(int num:nums){
            if(num%2!=0){
                long long nooc=(eoe+ete+1)%MOD;
                long long ntoc=eoo;
                eoo=(eoo+nooc)%MOD;
                eto=(eto+ntoc)%MOD;
            }else{
                long long noec=(eoo+eto+1)%MOD;
                long long ntec=eoe;
                eoe=(eoe+noec)%MOD;
                ete=(ete+ntec)%MOD;
            }
        }long long ans=(eoe+ete+eto+eoo)%MOD;
        return static_cast<int>(ans);
    }
};