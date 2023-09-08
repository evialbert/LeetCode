class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int i=0, j=1, c=0, n = arr.size();
        while(i < n-1 && j < n){
            int diff = arr[j]-arr[i];
            if(diff > k) i++;
            else if(diff == k && i!=j){
                i++; c++; j++;
                while(i < n-1 && arr[i-1]==arr[i]) i++;
            }
            else{
                if(diff>=0) j++;
                else j=i+1;
            }
        }
        return c;
    }
};