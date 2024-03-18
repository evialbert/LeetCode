class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(p.begin(), p.end(), [&](auto &a, auto &b){
            return (a[0] < b[0]) || (a[0] == b[0] and a[1] < b[1]);
        }); 
        int n = p.size(), i = 0, ans = 0;
        while(i < n){
            int j = i + 1, mini = p[i][1];
            while(j < n and p[j][0] <= mini) mini = min(mini, p[j][1]), j++;
            i = j, ans++;
        }
        return ans;
    }
};