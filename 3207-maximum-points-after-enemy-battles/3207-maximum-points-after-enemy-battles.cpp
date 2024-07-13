class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int miniElement=INT_MAX;
        long long sum=currentEnergy;
        for(auto &it:enemyEnergies){
            sum+=it;
            miniElement=min(miniElement,it);
        }
        sum-=miniElement;
        if(currentEnergy<miniElement)return 0;
        return (sum/miniElement);
    }
};