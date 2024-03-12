class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int count = 0;
        int n = apple.length, m = capacity.length;
        Arrays.sort(capacity);
        int apple_sum = 0;
        for(int i = 0; i<n;i++){
         apple_sum += apple[i];
        }
        int capacity_sum = 0;
        for(int i = m-1;i>=0;i--){
           if(capacity_sum<apple_sum){
            count++;
            capacity_sum += capacity[i];
           }
        }
        return count;
    }
}