class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& left, vector<vector<int>>& right) {
        int n=left.size();
        vector<vector<int>> temp;
        long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=max(left[i][0],left[j][0]);
                int b=max(left[i][1],left[j][1]);
                int c=min(right[i][0],right[j][0]);
                int d=min(right[i][1],right[j][1]);
                if(a<c && b<d){
                    long side=0;
                    if((c-a)<(d-b)){
                        side=c-a;
                    }else{
                        side=d-b;
                    }
                    ans=max(ans,side*side);
                }
            }
        }
        return ans;
    }
};