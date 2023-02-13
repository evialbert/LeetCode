class Solution {
public:
    int maxJump(vector<int>& stones) {
        if(stones.size()==2)return stones[1];
        int ans = INT_MIN,x = INT_MIN;
        for(int i=0;i<stones.size()-2;i += 2){
            x = max(x,stones[i+2]-stones[i]);
        }
        ans = x;
        x = INT_MIN;
        int f = 1,i = stones.size()-1;
        while(i>=2){
            if(f && stones.size()%2){
                x = max(x,stones[i]-stones[i-1]);
                i-=1;
                f=0;
                continue;
            }
            else{
                x = max(x,stones[i]-stones[i-2]);
                i -= 2;
            }
        }
        ans = max(ans,x);
        return ans;
    }
};