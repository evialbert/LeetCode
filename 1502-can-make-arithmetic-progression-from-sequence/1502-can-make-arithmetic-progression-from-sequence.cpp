class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int prevDiff = abs(arr[0]-arr[1]);
        for(int i=1;i<arr.size()-1;i++){
            int diff = abs(arr[i]-arr[i+1]);
            if(prevDiff!=diff)
                return false;
        }
        return true;
    }
};