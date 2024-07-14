class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        Arrays.sort(enemyEnergies);

        if(currentEnergy == 0 || enemyEnergies[0] > currentEnergy) return 0;
        long points = 0;
        int i = 0;
        int j = enemyEnergies.length-1;

        while(i <= j){
            if(currentEnergy >= enemyEnergies[i]){
                points += currentEnergy / enemyEnergies[i];
                currentEnergy = currentEnergy %  enemyEnergies[i];
            }
            else{
                currentEnergy += enemyEnergies[j];
                j--;
            }
        }    

        return points; 
    }
}