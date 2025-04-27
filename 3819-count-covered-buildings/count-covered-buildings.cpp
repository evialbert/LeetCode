class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>> x(n+1, {INT_MAX, INT_MIN}), y(n+1, {INT_MAX, INT_MIN});

        for(auto i:buildings){
            x[i[0]].first = min(x[i[0]].first, i[1]);
            x[i[0]].second = max(x[i[0]].second, i[1]);
            y[i[1]].first = min(y[i[1]].first, i[0]);
            y[i[1]].second = max(y[i[1]].second, i[0]);
        }

        int covered = 0;
        for(auto i:buildings){
            if(i[1] > x[i[0]].first && i[1] < x[i[0]].second && i[0] > y[i[1]].first && i[0] < y[i[1]].second)
                covered++;
        }

        return covered;
        
    }
};