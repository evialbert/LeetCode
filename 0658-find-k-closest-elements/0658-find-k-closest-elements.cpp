class Solution {
public:
      vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n = arr.size();
            vector<int> ans;
            if(x < arr[0]){
                for(int i=0;i<k;i++) ans.push_back(arr[i]);
            }
            else if(x > arr[n-1]){
                for(int i=n-1;i>=n-k;i--) ans.push_back(arr[i]);
            }
            else{
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                int i= idx-1, j=idx;
                while(i>=0 and j<n and ans.size() < k){
                    int d1 = abs(arr[i]-x);
                    int d2 = abs(arr[j] - x);
                    if(d1 <= d2){
                        ans.push_back(arr[i]);
                        i--;
                    }
                    else if(d1 > d2){
                        ans.push_back(arr[j]);
                        j++;
                    }
                }
                while(i>=0 and ans.size() < k){
                    ans.push_back(arr[i]);
                    i--;
                }
                while(j<n and ans.size() < k){
                    ans.push_back(arr[j]);
                    j++;
                }
                
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};