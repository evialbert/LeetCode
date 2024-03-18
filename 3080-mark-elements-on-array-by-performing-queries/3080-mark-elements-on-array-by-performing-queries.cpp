class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> ans; // SC:O(n)
        
        unordered_map<int,bool> mp; // map -> {idx,visited}, SC:O(n)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap --> {val,idx}, SC:O(n)
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) { // TC:O(n) * O(logn) = O(n.logn)
            mp[i] = 0;
            pq.push({nums[i],i});
            sum += nums[i];
        }
        
        for(auto query : queries) { // TC:O(k) * O(n) = TC:O(k.n)
            int i = query[0];
            int k = query[1];
            
            // 1st task
            if(mp[i] == 0) {
                mp[i] = 1;
                sum -= nums[i];
            }
            
            // 2nd task
            while(!pq.empty() && k >= 1) { // TC:O(k.logn)
                pair<int,int> top = pq.top();
                pq.pop();
                if(mp[top.second] == false && k >= 1) {
                    // cout << top.first << " " << top.second << endl;
                    sum -= top.first;
                    mp[top.second] = 1;
                    k--;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};