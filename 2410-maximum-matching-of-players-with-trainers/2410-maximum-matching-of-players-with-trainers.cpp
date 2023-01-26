class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        while(i < players.size() && j < trainers.size())
        {
            if(players[i] <= trainers[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        
        return cnt;
    }
};