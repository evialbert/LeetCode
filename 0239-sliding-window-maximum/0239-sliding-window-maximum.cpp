class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int i=0,j=0;
        for(i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        for(;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            while(pq.top().second<=j) pq.pop();
            j++;
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};