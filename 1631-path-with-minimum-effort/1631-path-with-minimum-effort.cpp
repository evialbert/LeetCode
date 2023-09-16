class Node{
    public:
    int diff,x,y;
    Node(int diff,int x,int y){
        this->diff = diff;
        this->x = x;
        this->y = y;
    }  
};
class cmp{
    public:
    bool operator()(Node* a, Node*b){
        return a->diff > b->diff;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<Node*, vector<Node*>, cmp >pq;
        pq.push(new Node(0, 0, 0));
        
        int ans = 0;
        int diri[4] = {1, -1, 0, 0};
        int dirj[4] = {0, 0, -1, 1};
        
        while(!pq.empty()){
            int curEffort = pq.top()->diff;
            int curx = pq.top()->x;
            int cury = pq.top()->y;
            pq.pop();
            
           if(dist[curx][cury] != curEffort)continue;
            
            ans = max(ans,curEffort);
            if(curx == n-1 && cury == m-1)return ans;
            
            for(int i=0;i<4;i++){
                int newx = curx + diri[i];
                int newy = cury + dirj[i];
                if(newx >= n || newy >= m || newx < 0 || newy < 0){
                    continue;
                }
                
                int newEffort = abs(heights[newx][newy] - heights[curx][cury]);
                if(newEffort < dist[newx][newy]){
                    pq.push(new Node(newEffort, newx, newy));
                    dist[newx][newy] = newEffort;
                }
            }
        }
        return ans;
    }
};