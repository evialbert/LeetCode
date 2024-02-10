class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b){
            return ( sqrt(a[0]*a[0] + a[1]*a[1]) <  sqrt(b[0]*b[0] + b[1]*b[1]) );
        });              
        return {points.begin(),points.begin()+K};
    }
};