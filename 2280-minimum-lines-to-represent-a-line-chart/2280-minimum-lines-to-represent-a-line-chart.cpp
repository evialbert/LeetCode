class Solution {
public:
    int minimumLines(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int cnt=1;
        if(arr.size()==1){
            return 0;
        }
        for(int i=2;i<arr.size();i++){
            long x1 = arr[i-2][0],y1 = arr[i-2][1];
            long x2 = arr[i-1][0],y2 = arr[i-1][1];
            long x3 = arr[i][0],y3 = arr[i][1];
            
            long diff1 = (y2-y1)*(x3-x2); //avoid finding individual slope with division to avoid floating point errors
            long diff2 = (y3-y2)*(x2-x1);
            if(diff1!=diff2){
                cnt++;
            }
        }
        return cnt;
    }
};