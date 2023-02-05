class Solution {
public:
    
    int solve(map<int,int>& mp, int i, int maxNum, vector<int>& t){
        
        if(i>maxNum) return 0;
        if(t[i]!=-1) return t[i];
        return t[i]=max(mp[i]*i+solve(mp,i+2,maxNum,t),solve(mp,i+1,maxNum,t));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
            
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        
        sort(nums.begin(),nums.end());
        int maxNum=nums[n-1];
        vector<int> t(maxNum+1,-1);
        return solve(mp,nums[0],maxNum,t);
    }
};