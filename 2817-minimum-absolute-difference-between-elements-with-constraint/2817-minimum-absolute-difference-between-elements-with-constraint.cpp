class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
       
       multiset<int>st;
       int n=nums.size();
       int ans=INT_MAX;
        for(int j=x;j<n;j++)
           st.insert(nums[j]);

       for(int i=0;i<n-x;i++){

           auto it=st.lower_bound(nums[i]);
           ans=min(ans,abs(*it-nums[i]));
           if(it!=st.begin())
           it--;
           ans=min(ans,abs(*it-nums[i]));
          
           it=st.find(nums[i+x]);
           st.erase(it);
       }
       return ans;
    }
};