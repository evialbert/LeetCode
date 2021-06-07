class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        return find(sx, sy, tx, ty);
    }
    
    boolean find(int sx, int sy, int tx, int ty){
        while((tx > sx || ty > sy) && (tx > 0 && ty > 0)){
            if(tx > ty){
                int m = Math.max(1, (tx-sx) / ty);
                tx = tx-m*ty;
            }
            else{
                int m = Math.max(1, (ty-sy) / tx);
                ty = ty-m*tx;
            }
        }
        if(tx == sx && ty == sy) return true;
        return false;
    }
}