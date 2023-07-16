class Solution {
public:

    
    int maxBuilding(int n, vector<vector<int>>& rest) {
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int maxH = 0;
        int current = 0;
        rest.insert(rest.end(),{{1,0},{n,n-1}});
        sort(begin(rest),end(rest));
        for(int i=0;i<rest.size()-1;i++){
            int h1 = rest[i][1];
            int h2 = rest[i+1][1];
            int current = h1 + abs(rest[i][0]-rest[i+1][0]);
            if(current>h2){
                current = h2 + (current-h2)/2;
            }
            maxH = max(maxH,current);
            rest[i+1][1] = min (current, h2);
        }
        reverse(begin(rest),end(rest));
         maxH = 0;
         current = 0;
        for(int i=0;i<rest.size()-1;i++){
            int h1 = rest[i][1];
            int h2 = rest[i+1][1];
            int current = h1 + abs(rest[i][0]-rest[i+1][0]);
            if(current>h2){
                current = h2 + (current-h2)/2;
            }
            maxH = max(maxH,current);
            rest[i+1][1] = min (current, h2);
        }

        return maxH;
        
    }
};