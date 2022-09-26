class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int maxA=capacityA,maxB=capacityB,count=0,i=0,j=plants.length-1;
        while(j-i>=0 && i<plants.length && j>=0){
            if(i==j){
                if(Math.max(capacityA,capacityB)<plants[i])
                    count++;
                break;
            }
            if(capacityA>=plants[i])
                capacityA=capacityA-plants[i];
            else{
                count++;
                capacityA=maxA;
                capacityA=capacityA-plants[i];
            }
            i++;
            if(capacityB>=plants[j])
                capacityB=capacityB-plants[j];
            else{
                count++;
                capacityB=maxB;
                capacityB=capacityB-plants[j];
            }
            j--;  
        }
        return count;
    }
}