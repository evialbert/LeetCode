class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2,vector<int> {});
        map<int,int> lose;
        vector<int> win;
        
        for(int i=0; i<matches.size(); i++){
            win.push_back(matches[i][0]);
            lose[matches[i][0]] = 0;
        }
        
        for(int i=0; i<matches.size(); i++){
            if(lose[matches[i][1]] == NULL){
                lose[matches[i][1]] = 1;
            }
            else{
                lose[matches[i][1]]++;
            }
        }
        
        for(auto z : lose){
            if(z.second == 0){
                ans[0].push_back(z.first);
            }
            else if(z.second == 1){
                ans[1].push_back(z.first);
            }
        }
        
        return ans;
    }
};