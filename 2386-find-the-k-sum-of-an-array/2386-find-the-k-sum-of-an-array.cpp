class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]>=0) sum+=nums[i];
            else nums[i]*=-1;
        }
        sort(nums.begin(), nums.end());
        typedef pair<long long, int> p;
        priority_queue<p> pq;
        pq.push({sum-nums[0], 0});
        long long ans = sum;
        while(!pq.empty() && k>1) {
            p curr = pq.top();
            pq.pop();
            sum = curr.first;
            int i = curr.second;
            if(i<nums.size()-1) {
                pq.push({sum+nums[i]-nums[i+1], i+1});
                pq.push({sum-nums[i+1], i+1});
            }
            k--;
            ans = sum;
        }
     return ans;
    }
};