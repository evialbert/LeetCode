class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        for(int i = 0; i < arr.size(); i++){
            m1[arr[i]]++;
        }
        
        for(auto x : m1){
            m2[x.second]++;
        }
        
        for(auto x : m2){
            if(x.second > 1)return false;
        }
        
        return true;
    }
};