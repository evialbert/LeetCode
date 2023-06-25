class Solution {
public:
    vector<vector<int>> dp;
    
    int check(vector<int>&arr,int i,int end,int feul){
        
        if(feul<0) return 0;
        
        if(dp[i][feul]!=-1) return dp[i][feul];
        
        int sum=0;
        
        int n=arr.size();
        
        if(i==end) sum=1;
        
        
       for(int j=0;j<n;j++){
        if(i!=j and feul-abs(arr[i]-arr[j])>=0 ){
            sum+=check(arr,j,end,feul-abs(arr[i]-arr[j]));
            sum=sum%(1000000000+7);
        }
       }
        return dp[i][feul]=sum%(1000000000+7);
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel)     {
        dp.clear();
        dp.resize(locations.size()+1,vector<int>(fuel+1,-1));
       return check(locations,start,finish,fuel);    
    }
};