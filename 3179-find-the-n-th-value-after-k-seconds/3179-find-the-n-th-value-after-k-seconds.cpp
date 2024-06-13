class Solution {
public:
    int md=1e9+7;
    int valueAfterKSeconds(int n, int k) {
       vector<int> arr(n, 1);  
        for (int i=0;i<k;i++) {
            for(int j=1;j<n;j++){
                arr[j]=(arr[j]+arr[j-1])%md;
            }
        }
        
        return arr[n-1];
    }
};