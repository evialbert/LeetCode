/*
minimum removed = maximum non removed

beans = [4,1,6,5]
*/

class Solution {
    public long minimumRemoval(int[] beans) {
        Arrays.sort(beans) ;
        long totalBeans = 0 ;
        long maxNonRemoved = 0 ;
        int n = beans.length ;
        
        for (int i = 0; i < n; i++) {
            totalBeans += beans[i] ;
            maxNonRemoved = Math.max(maxNonRemoved, beans[i]*(n-i+0L)) ;
        }
        return (totalBeans - maxNonRemoved) ;
    }
}