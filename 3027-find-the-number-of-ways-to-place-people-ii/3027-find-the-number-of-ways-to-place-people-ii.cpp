class Solution {
public:
    static bool comparator(const vector<int> &v1, const vector<int> &v2){
        if(v1[0] < v2[0])   return true;
        else if(v1[0] > v2[0]) return false;

        return v1[1] > v2[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comparator);

        int ans = 0;
        for(int i=0; i<points.size()-1; ++i){
            int maxInBetweenJ = INT_MIN;
            for(int j=i+1; j<points.size(); ++j){
                if(points[i][1] >= points[j][1]){
                    if(maxInBetweenJ < points[j][1])
                        ++ans;

                    if(points[i][1] >= points[j][1])
                        maxInBetweenJ = max(maxInBetweenJ, points[j][1]);
                }
            }
        }

        return ans;
    }
};