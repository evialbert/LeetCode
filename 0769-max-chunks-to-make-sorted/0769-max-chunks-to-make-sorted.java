class Solution {
    public int maxChunksToSorted(int[] arr) {
        int max_so_far = arr[0], chunks = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] > max_so_far){
                max_so_far = arr[i];
            }
            if(max_so_far == i){
                chunks++;
            }
        }
        return chunks;
    }
}