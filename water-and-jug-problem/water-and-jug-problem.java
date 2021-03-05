class Solution {
   public boolean canMeasureWater(int x, int y, int z) {
        if(x + y < z)return false;
        if(z==0)return true;
        while(y>0){
            int tmp = y;
            y =  x % y;
            x = tmp;
        }
        return z % x == 0;
    }
}