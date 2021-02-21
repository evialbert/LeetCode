class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] res = new int[queries.length];
        int t = 0;  // the init even sum
        for(int k : A){
            if(k % 2==0)
                t+=k;
        }
        
        for(int i=0; i<queries.length; i++){
            // if origin is even
            if(A[queries[i][1]] % 2 == 0){
                // query is even, add them up
                if(queries[i][0] % 2==0)
                    res[i] = t+queries[i][0];
                // query is odd, reduce origin
                else
                    res[i] = t-A[queries[i][1]];
            }else{
                // origin is odd, query is even
                if(queries[i][0] % 2==0)
                    res[i] = t;
                else
                    res[i] = t+queries[i][0]+A[queries[i][1]];
            }
            A[queries[i][1]] += queries[i][0];
            // update current sum
            t=res[i];
        }
        return res;
    }
}