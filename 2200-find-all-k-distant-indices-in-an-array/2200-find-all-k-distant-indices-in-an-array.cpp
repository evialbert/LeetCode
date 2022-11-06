class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(nums[i] == key) q.push(i);
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(q.empty()) break;
            int idx = q.front();
            
            if(abs(idx - i) <= k) {
                ans.push_back(i);
            }
            else {
                if(i > idx) {
					// if not able to cover current index then surely can't cover indices after it
                    q.pop();
					
					// lets again try for current index
                    i--;
                }
            }
        }
        
        return ans;
    }
};