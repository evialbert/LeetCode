class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix;
        int sum = 0;
        long long cnt = 0;
        for(int i=0; i<n; i++){
            sum = sum + arr[i];
            if(sum%2 != 0) cnt++;
        }
        cnt = cnt + (cnt*(n-cnt));
        return cnt % 1000000007;
    }
};