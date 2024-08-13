class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ans = 0;
        vector<vector<int>>temp(n,vector<int>(11,0));
        vector<int>won(n,-1);
        for(auto i:pick){
            temp[i[0]][i[1]]++;
            if(temp[i[0]][i[1]]>i[0] && won[i[0]]==-1){
                ans++;
                won[i[0]]=1;
            }
        }
        return ans;
    }
};