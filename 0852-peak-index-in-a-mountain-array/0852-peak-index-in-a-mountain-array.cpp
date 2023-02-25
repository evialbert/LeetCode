class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0, end=arr.size()-1;
        return find(arr, start, end);
    }
    
    int find(vector <int> arr, int start, int end){
        while(start<end){
            int mid=start+(end-start);
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]>arr[mid-1])
                start=mid+1;
            else if(arr[mid]<arr[mid-1])
                end=mid-1;
        }
        return 0;
    }
};