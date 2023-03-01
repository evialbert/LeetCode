class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int high=arr.size()-1,low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]-mid > k) high=mid-1;
            else low=mid+1;
        }
        return k+low;
    }

};