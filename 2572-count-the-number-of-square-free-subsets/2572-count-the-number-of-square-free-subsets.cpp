class Solution {
public:
    int primelist[10] = {2,3,5,7,11,13,17,19,23,29};
    int checkprime(int n){
        int ret = 0;
        for(int i = 0 ;  i < 10 ; i++){
            if(n%primelist[i] == 0){
                n/=primelist[i];
                ret |= 1<<i;
            }
            if(n%primelist[i] == 0) return -1;
        }
        return ret;
    }
    int squareFreeSubsets(vector<int>& nums) {
        int MOD = 1e9+7, cnt = 0;
        vector<int> bitmap(nums.size());
        for(auto &v:nums){
            auto ret = checkprime(v);
            if(ret != -1)   bitmap[cnt++] = ret;
        }
        int m[1024] = {0};
        int ans = 0;
        while(cnt > 0){
            cnt--;
            for(int k = 0 ; k < 1024 ; k++){     // add new digits after combination
                if(m[k] != 0 && (k&bitmap[cnt]) == 0){
                    m[(k|bitmap[cnt])] = (m[(k|bitmap[cnt])] + m[k])%MOD;
                }
            }
            m[bitmap[cnt]]++;
        }
        for(int i = 0 ; i < 1024 ; i++){
            ans = (ans + m[i])%MOD;
        }
        return ans;
    }
};