class Solution {
public:
    int countTriplets(vector<int>& arr) {
       int r=0;
        for(int i=0;i<arr.size();i++) {
            int acc=arr[i];
            for(int k=i+1;k<arr.size();k++) {
                acc^=arr[k];
                if(acc==0)
                    r+=k-i;
            }
        }
        return r;  
    }
};