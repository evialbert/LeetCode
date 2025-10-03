class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> rD(n);
        for(int i = 0; i<n; ++i) rD[i] = {robots[i],distance[i]};
        sort(rD.begin(),rD.end());
        sort(walls.begin(),walls.end());
        int dp0 = 0, dp1 = 0;
        auto cnt = [&](int x, int y){
            return upper_bound(walls.begin(),walls.end(),y) - lower_bound(walls.begin(),walls.end(),x); 
        };
        for(int i = 0; i<n; ++i){
            int after = rD[i].first + rD[i].second,before0 = rD[i].first-rD[i].second, before1 = before0; 
            if(i!=n-1) after = min(after,rD[i+1].first-1);
            if(i!=0) {
                before0 = max(before0,rD[i-1].first+1),
                before1 = min(rD[i].first,max(before0,rD[i-1].first+rD[i-1].second+1)); 
            }
            int new_dp1 = max(dp0,dp1)+cnt(rD[i].first,after);
            int new_dp0 = max(dp0+cnt(before0,rD[i].first), dp1+cnt(before1,rD[i].first));
            dp0=new_dp0, dp1=new_dp1;
        }
        return max(dp0,dp1);
    }
};