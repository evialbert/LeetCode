class Solution {
private:
    int earliestFin(vector<int>& aS , vector<int>& aD , vector<int>& bS , vector<int>& bD){
        int early = INT_MAX;
        for(int i = 0, n = aS.size(); i < n; ++i) early = min(early , aS[i] + aD[i]);
        int res = INT_MAX;
        for(int j = 0, m = bS.size(); j < m; ++j) res = min(res , max(early , bS[j]) + bD[j]);
        return res;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirst = earliestFin(landStartTime , landDuration , waterStartTime, waterDuration);
        int waterFirst = earliestFin(waterStartTime , waterDuration , landStartTime , landDuration);
        return min(landFirst , waterFirst);
    }
};