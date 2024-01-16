class Solution {
    private long nth (long max, long num, long add, long sum, long x) {
        if (sum + add > max)
            return num -1;

        long curnum = 1;
        long curSum = 0;
        long sw = 1; //switch
        
        while (true) {
            long temp =  (sw % x == 0 ? 1 : 0) * curnum + 2 * curSum;
            if (sum + (2 * add * curnum) + temp > max) {
                if (curnum == 1)
                    return num;
                else
                    return  num + nth(max, curnum, add + (sw % x == 0 ? 1 : 0), sum + curSum + ( add * curnum), x);
            }
            curSum = temp;
            curnum *= 2;
            sw++;
        }
    }
    public long findMaximumNumber(long k, int x) {
        return nth(k, 0, 0, 0, x);
    }
}