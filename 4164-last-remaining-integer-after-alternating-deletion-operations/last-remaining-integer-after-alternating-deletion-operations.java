class Solution {
    public long lastInteger(long n) {
        long last = n;
        long dif = 1;
        long m = n;
        while(m > 2) {
            if(m%2 == 0) {
                last-= dif;
            }
            //if()
                dif*= 4;
                m = (m+1)/2;
                 m = (m+1)/2;
        }

        if(m == 2) return (last-dif);
        return last;
    }
}