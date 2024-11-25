class Solution {
public:
    int ans = INT_MAX;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    string toString (vector<vector<int>> & b) {
        string hash = "";
        for(int i=0;i<2;i++) {
            for(int j=0;j<3;j++) {
                hash += to_string(i);
                hash += to_string(b[i][j]);
            }
        }
        return hash;
    }
    bool isValid(int x, int y) {
        return (x>=0 && x<2 && y>=0 && y<3);
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> visited;
        queue<pair<vector<vector<int>>, int>> Q;
        string target = "010203141510";
        string hash = toString(board);
        visited[hash] = 1;
        if(hash == target) {
            return 0;
        }
        Q.push({board, 0});
        while(!Q.empty()) {
            vector<vector<int>> u = Q.front().first;
            int dist = Q.front().second;
            Q.pop();
            for(int i=0;i<2;i++) {
                for(int j=0;j<3;j++) {
                    if(u[i][j]==0) {
                        for(int k=0;k<4;k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(isValid(x,y)) {
                                vector<vector<int>> copy = u;
                                swap(copy[i][j], copy[x][y]);
                                hash = toString(copy);
                                if(!visited[hash]) {
                                    visited[hash] = 1;
                                    Q.push({copy, dist+1});
                                    if(hash==target) {
                                        return dist + 1;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        return -1;
    }
};