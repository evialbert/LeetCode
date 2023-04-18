class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int cnt = 0;
        map<int, int> suf, pref;
        for(auto i : nums){
            for(int j = 2; j <= sqrt(i); j++){
                while(i%j == 0){
                    suf[j]++;
                    i/=j;
                }
            }
            if(i>=2) suf[i]++;
        }
        for(int i=0; i<nums.size()-1; i++){
            int d=nums[i];
            for(int j = 2; j <= sqrt(d); j++){
                while(d%j == 0){
                    pref[j]++;
                    suf[j]--;
                    d/=j;
                    if(suf[j] == 0) cnt++;
                }
            }
            if(d>=2) {
                pref[d]++;
                suf[d]--;
                if(suf[d] == 0) cnt++;
            }
            if(cnt==pref.size()) return i;
        }
        return -1;
    }
};