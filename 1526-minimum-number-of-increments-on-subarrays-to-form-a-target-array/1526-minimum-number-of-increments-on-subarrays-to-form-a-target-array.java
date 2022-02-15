class Solution {
  public static int minNumberOperations(int[] target) {
        int pre = 0, count = 0;
        for(int i : target){
            if(i > pre){
                count += i-pre;
            }
            pre = i;
        }
        return count;
    }
}