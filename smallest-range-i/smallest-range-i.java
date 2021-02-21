class Solution {
    public int smallestRangeI(int[] A, int K) {
        
        int min=A[0];
        int max=A[0];
        for(int i=0;i<A.length;++i)
        {
            if(A[i]>=max)
                max=A[i];
            if(A[i]<=min)
                min=A[i];
        }
        min=min+K;
        max=max-K;
        if(max>min)
            return max-min;
        else
            return 0;
        
        
    }
}