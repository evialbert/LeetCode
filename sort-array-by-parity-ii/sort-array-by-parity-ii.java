class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] result = new int[A.length];
        int indexOfEven = 0;
        int indexOfOdd = 1;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0){
                result[indexOfEven] = A[i];
                indexOfEven += 2;
            }else{
                result[indexOfOdd] = A[i];
                indexOfOdd += 2;
            }
        }
        return result;
    }
}