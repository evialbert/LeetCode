class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int steps=0, can=capacity;
        for(int i=0;i<plants.length;i++){
            if(plants[i]<=can){
                steps++;
                can-=plants[i];
            }
            else{
                steps+= i+(i+1);
                can= capacity;
                can-= plants[i];
            }
        }
        return steps;
    }
}