class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            if(mp.find(arr2[i]) != mp.end()){
                int a = mp[arr2[i]];
                while(a--){
                    ans.push_back(arr2[i]);
                }
            }
        }
        unordered_set<int>s;
       // vector<int>ans2;
        for(int i=0;i<arr2.size();i++){
            s.insert(arr2[i]);
        }
        vector<int>s2;
        for(int i=0;i<arr1.size();i++){
            if(s.find(arr1[i]) == s.end()){
                s2.push_back(arr1[i]);
            }
        }
        sort(s2.begin(),s2.end());
        for(auto i:s2){
            ans.push_back(i);
        }
        return ans;
    }
};