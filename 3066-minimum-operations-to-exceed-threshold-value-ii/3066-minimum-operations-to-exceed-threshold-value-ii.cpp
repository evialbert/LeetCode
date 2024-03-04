class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int ans=0;
        while(pq.size()>=2 && pq.top()<k){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            long long temp=(long long)min(a,b)*2 +max(a,b);
            pq.push(temp);
            ans++;
        }
        return ans;
    }
};