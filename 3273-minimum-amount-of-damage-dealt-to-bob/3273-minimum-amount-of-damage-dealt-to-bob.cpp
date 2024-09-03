class Solution {
public:
    static bool compare(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return a.first * b.second > b.first * a.second;
    }
    
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<long long, long long>> mpp;

        for(int i = 0 ; i < n ; i++){
            long long Health = health[i];
            long long timeOne = ceil(((double)Health)/power); 
            mpp.push_back({(long long)damage[i], timeOne});
        }

        sort(mpp.begin(), mpp.end(), compare);
        long long ans = 0;
        long long accumulated = 0;
        for(int i = 0 ; i < mpp.size() ; i++){
            accumulated += mpp[i].first;
        }

        for (auto enemy : mpp) {
            long long time = enemy.second;
            ans = ans + accumulated * time;  
            accumulated -= enemy.first; 
        }

        return ans;
    }
};