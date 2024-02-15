class Solution {
public:
    void CountKMPtable(vector<int>& map,vector<int>& next){
        int len=0,i=1;
        while(i<map.size()){
            if(map[i]==map[len]){
                next[i]=len+1;
                len+=1;
                i++;
            }else{
                if(len!=0) len=next[len-1];
                else{
                    next[i]=0;
                    i++;
                }
            }
        }
    }
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        vector<int> map(n-1,0),next(n-1,0);
        vector<int> start;
        for(int i=0;i+1<n;i++){
            if(nums[i+1]>nums[i]) map[i]=1;
            else if(nums[i+1]==nums[i]) map[i]=0;
            else if(nums[i+1]<nums[i]) map[i]=-1;
            
            if(map[i]==pattern[0]) start.push_back(i);
        }
        CountKMPtable(pattern,next);
        int ans=0,j=0;
        for(int i=0;i<map.size();i++){
            while(j!=0 && pattern[j]!=map[i]) j=next[j-1];
            if(pattern[j]==map[i]) j++;
            if(j==pattern.size()){
                ans++;
                j=next[j-1];
            }
        }
        return ans;
    }
};