class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        //Sorting helps to find the best suitable asteroid greedily to destroy
         Arrays.sort(asteroids);
         long cm = mass;
         for(int val : asteroids){
             if(cm >= val){
                 cm += val;
             }
             else return false;
         }
        return true;
    }
}