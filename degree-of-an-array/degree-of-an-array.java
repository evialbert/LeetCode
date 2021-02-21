class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, int[]> map = new HashMap<>();
        int max = 0;
        for(int j=0; j<nums.length; j++){
            int i = nums[j];
            if(map.containsKey(i)){
                int[] temp = map.get(i);
                temp[0]++;
                temp[2] = j;
                map.put(i, temp);
            }else{
                int[] temp = new int[]{1, j, j};
                map.put(i, temp);
            }
            max = Math.max(map.get(i)[0], max);
        }
        int min = Integer.MAX_VALUE;
        for(Map.Entry<Integer, int[]> e: map.entrySet()){
            if(e.getValue()[0] == max){
                min = Math.min(min, e.getValue()[2] - e.getValue()[1] + 1);
            }
        }
        return min;
    }
}