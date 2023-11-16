class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        unordered_map<string, vector<int>> mp;
        
        for(int i=0 ;i<access_times.size() ;i++)
            mp[access_times[i][0]].push_back(stoi(access_times[i][1]));        
        
        vector<string> ans;
        
        for(auto pa:mp){
            vector<int> temp = pa.second;
            sort(temp.begin(), temp.end());
            
            // we just need to check a pair of 3 system.
            for(int i=2 ;i<temp.size() ;i++){
                if(temp[i]-temp[i-2]<100){
                    ans.push_back(pa.first);
                    break;
                }
            }
        }
        return ans;
    }
};