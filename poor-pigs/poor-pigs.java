class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int time = (minutesToTest / minutesToDie) + 1;
        int pigs = 0;
        int total = 1;
        
        while (total < buckets) {
            ++pigs;
            total *= time;
        }
        
        return pigs;
    }
}