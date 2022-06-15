class Solution {
    public int getXORSum(int[] arr1, int[] arr2) {
        int unique1=0;
        int unique2=0;
        for(int item1:arr1){
            unique1^=item1;
        }
        for(int item2:arr2){
            unique2^=item2;
        }
            
        return unique1 & unique2;
    }
}