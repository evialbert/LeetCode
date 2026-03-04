class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> arr(n,1e9);

        for(auto temp:restrictions){
            arr[temp[0]] = temp[1];
        }
        arr[0] = 0;
        int value = 1e9;
        for(int i = n-2; i>=0; i--){
            arr[i] = min(arr[i],arr[i+1]+diff[i]);
        }
        int result = INT_MIN;
        for(int i = 1; i<n; i++){
            arr[i] = min(arr[i],arr[i-1]+diff[i-1]);
            result = max(result,arr[i]);
        }
        return result;
    }
};