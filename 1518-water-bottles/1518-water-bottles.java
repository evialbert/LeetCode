//Using Recursion

class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while(numBottles >= numExchange){
            numBottles -= numExchange;
            result++;
            numBottles++;
        }
        if(numBottles < numExchange){
            return result;
        } else {
            return numWaterBottles(numBottles, numExchange);
        }
    }
}