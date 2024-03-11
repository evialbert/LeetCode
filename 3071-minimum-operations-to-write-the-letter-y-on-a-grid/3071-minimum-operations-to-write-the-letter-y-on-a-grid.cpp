class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        map<int,int> mp1;
        map<int,int> mp2;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i==j and i<=n/2) or (j==n/2 and i>n/2) or (j==(n-1-i) and i<=n/2)){
                    mp1[grid[i][j]]++;
            
                }
                else{
                    mp2[grid[i][j]]++;
                 
                }
            }
        }
        int ans=INT_MAX;
        int totalNotY=mp2[0]+mp2[1]+mp2[2];
        int totalY=mp1[0]+mp1[1]+mp1[2];
        vector<int> arr1(3);
        vector<int> arr2(3);
        arr1[0]=totalY-mp1[0];
        arr1[1]=totalY-mp1[1];
        arr1[2]=totalY-mp1[2];
        arr2[0]=totalNotY-mp2[0];
        arr2[1]=totalNotY-mp2[1];
        arr2[2]=totalNotY-mp2[2];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j){
                    ans=min(ans,arr1[i]+arr2[j]);
                }
            }
        }
        return ans;
    }
};