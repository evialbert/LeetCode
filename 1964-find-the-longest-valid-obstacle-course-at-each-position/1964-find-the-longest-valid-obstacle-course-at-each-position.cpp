class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 1), lis;
        for(int i = 0; i < n; i++){
            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if(idx == lis.size()){
                lis.push_back(obstacles[i]);
            } else {
                lis[idx] = obstacles[i];
            }
            ans[i] = idx + 1;
        }
        return ans;
    }
};