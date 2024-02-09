class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int i=n-1; i>0; i--) {
            int maxi=INT_MIN,ind,j=0;
            for(j=0; j<=i; j++) {
                if(maxi < arr[j]) {
                    maxi = arr[j];
                    ind = j;
                }
            }
            if(ind==i)
                continue;
            if(j!=0) {
                ans.push_back(ind+1);
                reverse(arr.begin(),arr.begin()+ind+1);
            }
            ans.push_back(i+1);
            reverse(arr.begin(),arr.begin()+i+1);
        }
        return ans;
    }
};