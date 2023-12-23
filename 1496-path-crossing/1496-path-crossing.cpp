class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        int x = 0 , y = 0;
        set<pair<int,int>> st;
        st.insert({x,y});
        for(int i=0;i<n;i++){
            if(path[i]=='N') y++;
            else if(path[i]=='S') y--;
            else if(path[i]=='E') x++;
            else x--;
            if(st.find({x,y})!=st.end()) return true;
            st.insert({x,y});
        }
        return false;
    }
};