class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++){
            arr[i] += arr[i-1];
        }

        int last = arr[arr.size()-1];
        if(last%3 != 0)return false;

        bool first = false;
        for(int i = 0; i < arr.size()-1; i++){
           if(!first && arr[i] == last/3)first = true;
           else if(first && arr[i] == (last*2)/3)return true;
        }

        return false;
    }
};