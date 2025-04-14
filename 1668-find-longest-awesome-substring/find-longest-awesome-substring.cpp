class Solution {
public:
    int longestAwesome(string s) {
        int mask = 0;  int n = s.size(); int ans = 0;
        vector<int>arr(1024,n);
        arr[0] = -1;

        for(int i = 0; i<n; i++){
            mask = mask ^ (1 << (s[i]-'0'));
            ans = max(ans , i - arr[mask]);

            for(int j = 0; j<10; j++){
                int temp = mask^(1<<j);
                ans = max(ans , i- arr[temp]);
            }

            arr[mask]=  min(arr[mask] , i);
        }
        return ans;
    }
};