class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) {
        
      sort(arr.begin(),arr.end());
      int n = arr.size();
      int ans = arr[n-1]-arr[0];
      int maxdiff,mindiff ;
      for(int i=1;i<n;i++)
      {
        maxdiff = max(arr[n-1]-k,arr[i-1]+k);
        mindiff = min(arr[0]+k,arr[i]-k);
        ans = min(ans,maxdiff-mindiff);
      }
      return ans;
    }
};