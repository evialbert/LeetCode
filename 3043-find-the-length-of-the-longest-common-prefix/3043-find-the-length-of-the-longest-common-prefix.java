class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> set = new HashSet<>();
        for(int no: arr1){
            while(no > 0){
                set.add(no);
                no /= 10;
            }
        }

        int maxlen = 0;
        for(int no: arr2){
            while(no > 0){
                if(set.contains(no)){
                    maxlen = Math.max(maxlen, Integer.toString(no).length());
                }
                no /= 10;
            }
        }
        return maxlen;
    }
}