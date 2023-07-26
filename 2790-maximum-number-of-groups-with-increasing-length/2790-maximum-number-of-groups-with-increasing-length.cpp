class Solution {
public:
    int maxIncreasingGroups(vector<int>& lim) {
        sort(lim.begin(),lim.end());
        int cnt=0;
        long long sm=0;
        for(auto x:lim){
            sm+=x;

            if(sm >= cnt+1){
                sm-=(cnt+1);
                cnt++;
            }
        }
        return cnt;
            
    }
};