class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end()); //sort the array
        arr[0] = 1; //assign first element with 1
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] != arr[i-1]) 
              arr[i] = arr[i-1]+1; 
        }
    return arr.back(); //return the last element
    }
};