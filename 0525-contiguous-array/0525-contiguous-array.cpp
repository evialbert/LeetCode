class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int ans=0;
        unordered_map<int,int>post;
        post[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                count++;
            else
                count--;
                
            if(post.contains(count)){
                ans=max(ans,(i)-post[count]);
            }
            else{
                post[count]=i;   
            }
        } 
        return ans;
        
    }
};