class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        const double d = angle / 180.0 * M_PI;
        vector<double> v;
        int res = 0, countOrigin = 0;
        for (auto& p : points){
            auto x = p[0] - location[0], y = p[1] - location[1];
            if(x == 0 && y==0) countOrigin++;
            else v.push_back(atan2(x, y));
        }
        sort(v.begin(), v.end());
        for(int i=0, n=v.size(); i<n;i++) v.push_back(v[i] + 2*M_PI);
        for(int i=0,j=0,n=v.size();j<n;i++){
            while(j<n && v[j] - v[i] <= d) {
                res = max(res, j-i+1);
                j++;
            }
        }
        return res + countOrigin;
    }
};