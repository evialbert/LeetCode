class Solution {
public:
    int solve(vector<int>cur,vector<int>prev){
        int x = abs(cur[0]-prev[0]);
        int y = abs(cur[1]-prev[1]);
        return max(x,y);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 1;i < points.size();i++){
            time += solve(points[i],points[i-1]);
        }
        return time;
    }
};