class Solution {
public:
    int findMin(vector<int>& num) {
        int n = num.size();
        int low = 0, high = n-1;
        
        while (low<high){
            if (num[low]<num[high])
                return num[low];
            
            int mid = (low+high)/2;
            
            if (num[mid]>=num[low]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return num[low];
    }
};