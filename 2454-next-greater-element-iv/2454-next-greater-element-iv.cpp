class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            while (!pq2.empty() and pq2.top().first < n) {
                res[pq2.top().second] = n;
                pq2.pop();
            }
            while (!pq1.empty() and pq1.top().first < n) {
                pq2.push(pq1.top());
                pq1.pop();
            }
            pq1.push({n, i});
        }

        return res;
    }
};