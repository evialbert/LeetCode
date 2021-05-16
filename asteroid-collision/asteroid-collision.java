class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int i=0;
        int j=1;
        int n= asteroids.length;
        while(j<n){
            if(i>=0 && asteroids[i]>0 && asteroids[j]<0){
                if(asteroids[i]==Math.abs(asteroids[j])){
                    i--;
                    j++;
                } else if(asteroids[i]>Math.abs(asteroids[j])){
                    j++;
                } else{
                    i--;
                }
            } else{
                asteroids[i+1]= asteroids[j];
                i++;
                j++;
            }
        }
        int[] ans= new int[i+1];
        for(int k=0;k<=i;k++)
            ans[k]=asteroids[k];
        return ans;
    }
}