class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum=0;
        for(auto it:nums)sum+=it;
        if(sum<target)return -1;
        priority_queue<int>pq;
        for(auto it:nums)pq.push(it);
        int ans=0;
        while(target>0){
            auto it=pq.top();
            pq.pop();
            sum-=it;
            if(it<=target){
                target-=it;
            }
            else if(it>target && sum<target){
                ans++;
                sum+=it;
                pq.push(it/2);
                pq.push(it/2);
            }
        }
        return ans;
    }
};