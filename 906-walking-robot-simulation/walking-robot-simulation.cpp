class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int x = 0, y = 0;
        string dir = "N";
        int ans = 0;
        
        set<pair<int,int>> obs;
        for(auto o : obstacles)
            obs.insert({o[0], o[1]});
        
        for(int cmd : commands) {
            
            if(cmd == -2) {
                if(dir == "N") dir = "W";
                else if(dir == "W") dir = "S";
                else if(dir == "S") dir = "E";
                else if(dir == "E") dir = "N";
            }
            else if(cmd == -1) {
                if(dir == "N") dir = "E";
                else if(dir == "E") dir = "S";
                else if(dir == "S") dir = "W";
                else if(dir == "W") dir = "N";
            }
            else {
                for(int i = 0; i < cmd; i++) {
                    int nx = x, ny = y;
                    
                    if(dir == "N") ny++;
                    else if(dir == "S") ny--;
                    else if(dir == "E") nx++;
                    else if(dir == "W") nx--;
                    
                    if(obs.count({nx, ny})) break;
                    
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        
        return ans;
    }
};