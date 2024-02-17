class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), ans1 = 0, ans2 = 0;
        if(n == 1) return 0;
        priority_queue<int, vector<int>, greater<int>> ladderAllocatons;
        
        for(int i = 0; i < n - 1; i++){
            int climb = heights[i + 1] - heights[i];
            if(climb <= 0) continue;
            ladderAllocatons.push(climb);
            
            if(ladderAllocatons.size() <= ladders) continue;
            
            bricks -= ladderAllocatons.top();
            ladderAllocatons.pop();
            
            if(bricks < 0) return i;
        }
        return n - 1;
    }
};