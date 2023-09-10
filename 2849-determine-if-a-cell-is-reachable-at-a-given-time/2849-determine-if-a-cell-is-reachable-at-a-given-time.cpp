class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        if(t==1 && sx==fx && sy==fy){
            return false;
        }
        int ans=max(x,y);
        if(ans<=t){
            return true;
        }
        else return false;
    }
};