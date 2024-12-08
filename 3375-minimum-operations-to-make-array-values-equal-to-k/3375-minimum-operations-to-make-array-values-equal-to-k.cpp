class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto a : nums){
            pq.push(a);
            if(a < k){
                return -1;
            }
        }
        int ans = 0;
        while(!pq.empty() && pq.top() != k){
            auto it = pq.top();
            pq.pop();
            while(!pq.empty() && pq.top() == it){
                pq.pop();
            }
            ans += 1;
        }
        return ans;
    }
};