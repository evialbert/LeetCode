class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0; int drunk = 0;
        while(numBottles > 0){
            empty += numBottles;
            drunk += numBottles;
            numBottles = 0;
            while(empty >= numExchange){
                numBottles += 1;
                empty -= numExchange;
                numExchange++;
            }
        }
        return drunk;
    }
}