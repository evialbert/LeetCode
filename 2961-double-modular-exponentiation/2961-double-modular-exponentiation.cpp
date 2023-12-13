class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        vector<int> res;
        
        for(int i=0; i<n; i++){
            long long temp = 1;
            for(int j=0; j<arr[i][1]; j++){
                temp = (temp * (long long)(arr[i][0])) % 10;
            }
            
            temp = temp % 10;
            long long curr = temp;
            for(int j=0; j<arr[i][2]-1; j++){
                temp = (temp * curr) % (long long)(arr[i][3]);
            }
            
            temp = temp % (long long)(arr[i][3]);
            if(temp == (long long)target)
                res.push_back(i);
        }
        return res;
    }
};