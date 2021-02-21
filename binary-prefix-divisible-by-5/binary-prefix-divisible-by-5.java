class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
     List<Boolean> res = new ArrayList<>(A.length);

        int a = 0;

        for(int i=0; i<A.length; i++){

            a<<=1;

            a+=A[i];

            res.add(a%5==0);

            a%=10;
            

        } 
         return res;

    }
    
}