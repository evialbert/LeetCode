class Solution {
private:
     vector<int> minOnleft(vector<int>& nums) {
         int n = nums.size();
         vector<int> ans(n);
         
         stack<int> s;
         for(int i = 0; i < n; i++) {
             if(s.empty()) {
                 s.push(i);
                 ans[i] = -1;
             }
             else {
                 while(!s.empty() and nums[i] < nums[s.top()]) {
                     s.pop();
                 }
                 if(s.empty()) {
                     ans[i] = -1;
                 }
                 else {
                     ans[i] = s.top();
                 }
             }
             s.push(i);
         }
         return ans;
     }
    
    vector<int> minOnRight(vector<int>& nums) {
         int n = nums.size();
         vector<int> ans(n);
         
         stack<int> s;
         for(int i = n - 1;i >= 0; i--) {
             if(s.empty()) {
                 s.push(i);
                 ans[i] = -1;
             }
             else {
                 while(!s.empty() and nums[i] < nums[s.top()]) {
                     s.pop();
                 }
                 if(s.empty()) {
                     ans[i] = -1;
                 }
                 else {
                     ans[i] = s.top();
                 }
             }
             s.push(i);
         }
         return ans;
     }

public:
    long long maximumSumOfHeights(vector<int>& nums) {
        vector<int> left = minOnleft(nums);
        vector<int> right = minOnRight(nums);
        
        int n = nums.size();
        
        if(n == 1) {
            return nums[0];
        }
        
        vector<long long> dp1(n , 0);
        
        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            
            if(i == 0) {
                dp1[i] = nums[i];
                continue;
            }
            
            int sol = left[i];
            if(sol == -1) {
                dp1[i] = (i + 1) *1ll* nums[i];
            }
            else {
                dp1[i] = dp1[sol] + (i - sol) *1ll* nums[i];  
            }
        }
        
        
        vector<long long> dp2(n , 0);
        
        for(int i = n - 1; i >= 0; i--) {
            int ele = nums[i];
            
            if(i == n - 1) {
                dp2[i] = nums[i];
                continue;
            }
            
            int sor = right[i];
            if(sor == -1) {
                dp2[i] = (n - i) *1ll* nums[i];
            }
            else {
                dp2[i] = dp2[sor] + (sor - i) *1ll* nums[i];
            }
        }
        

        
        long long finalans = -1;
        
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                finalans = max(finalans , dp2[i]);
            }
            else if(i == n - 1) {
                finalans = max(finalans , dp1[i]);
            }
            else {
                finalans = max(finalans , dp2[i] + dp1[i] - nums[i]);
            }
        }
        return finalans;
    }
};