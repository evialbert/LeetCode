class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        vector<pair<int,int>> moves{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<pair<int,int>> dest(pieces.size());
        vector<int> move(pieces.size());
        int result = 0;

        function<bool()> simulate = [&]() {
            vector<vector<int>> pos = positions;

            while(true) {
                bool finished = true;

                // move all pieces by 1 square
                for(int i=0; i<pieces.size(); i++) {
                    int sx = pos[i][0]-1, sy = pos[i][1]-1;
                    auto [tx, ty] = dest[i];

                    if(sx != tx or sy != ty) {
                        finished = false;
                        auto [dx, dy] = moves[move[i]];
                        pos[i][0] += dx;
                        pos[i][1] += dy;
                    }
                }

                // check for collisions
                for(int i=0; i<pieces.size(); i++) {
                    for(int j=i+1; j<pieces.size(); j++) {
                        if(pos[i][0] == pos[j][0] and pos[i][1] == pos[j][1]) return false;
                    }
                }

                if(finished) break;
            }

            return true;
        };

        function<void(int)> generate = [&](int i) {
            if(i == pieces.size()) {
                result += simulate();
                return;
            }

            int start, end;

            if(pieces[i] == "rook") start = 0, end = 3;
            else if(pieces[i] == "bishop") start = 4, end = 7;
            else start = 0, end = 7;

            dest[i] = {positions[i][0]-1, positions[i][1]-1};
            generate(i+1);
            
            for(int j=start; j<=end; j++) {
                auto [dx, dy] = moves[j];
                move[i] = j;

                for(int x = positions[i][0]-1+dx, y = positions[i][1]-1+dy; x>=0 and x<8 and y>=0 and y<8; x += dx, y += dy) {
                    dest[i] = {x, y};
                    generate(i+1);
                }
            }
        };

        generate(0);

        return result;
    }
};