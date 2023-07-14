class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        //map to store the element, length of longest arithmetic subsequence till that element
        unordered_map<int, int> dp;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            //we need to find this nummber in the (0 --> i-1 elements), 
            int temp = arr[i] - difference;
            //if it doesn't exist this ith number will start a new AP with length 1
            int cnt = 1;
            //if it exist then prev length + 1 will be the length of the AP of which the ith index is part of 
            if(dp.count(temp)) cnt = 1+dp[temp];
            
            //store the lenght and take the max
            dp[arr[i]] = cnt;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};