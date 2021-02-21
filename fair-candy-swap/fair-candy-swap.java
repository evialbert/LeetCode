class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sumA = 0;
        int sumB = 0;
        for(int a : A)
            sumA+=a;
         for(int b : B)
            sumB+=b;
        int avg = (sumA+sumB)/2;
        int targetA = avg-sumA;
        Arrays.sort(B);
        for(int a:A){
            if(Arrays.binarySearch(B,a+targetA)>=0)
                return new int[]{a,a+targetA};
        }
        return null;
    }
    
   
}