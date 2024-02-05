class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(i == j) continue;
                
                if(points[j][0] >= points[i][0] && points[j][1] <= points[i][1]){
                    // vector<vector<int>> dirs = {points[i],points[j],
                    //                             {points[i][0], points[j][1]},{points[i][1], points[j][0]}};
                    bool flag = true;
                    for(int k=0; k<points.size(); k++){
                        if(i == k or j == k) continue;
                        if(points[i][0] <= points[k][0] && points[k][0] <= points[j][0]
                            && points[j][1] <= points[k][1] && points[k][1] <= points[i][1]){
                            flag = false;
                        }
                    }
                    if (flag) ans++;
                }
                
            }
        }
        return ans;
    }
};