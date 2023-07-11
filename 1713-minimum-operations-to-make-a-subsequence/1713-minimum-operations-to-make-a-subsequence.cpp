class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int, int>mp;
        vector<int>temp;
        vector<int>seq;
        // make a map to store the indices for target elements
        for(int i=0;i<target.size();i++){
            mp[target[i]]= i;
        }
        // push indices of target elements present in arr also
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) !=mp.end()){
                temp.push_back(mp[arr[i]]);
            }
        }
        // find the LIS of indices array of target elements present in arr 
        for(int i=0;i<temp.size();i++){
            if(seq.size()==0 || seq.back()<temp[i]){
                seq.push_back(temp[i]);
            }
            else{
                int idx = lower_bound(seq.begin(), seq.end(), temp[i]) - seq.begin();
                seq[idx] = temp[i];
            }
        }
        return target.size()- seq.size();
    }
};