class Solution {
public:
    int solve(vector<int>& arr,int& target,int mid){
        int sum = 0;
        for(auto & it : arr){
            sum += min(it,mid);
        }
        return abs(sum - target);
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int diff = INT_MAX;
        int start = 0;
        int end = target;
        int ans = -1;
        while(start <= end){
            int mid = start + ((end - start) >> 1);
            if(solve(arr,target,mid) <= solve(arr,target,mid+1)){
                end = mid-1;
                ans = mid;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};