
class Solution {
public int subarraySum(int[] nums, int k) {
    Map<Integer,Integer> count = new HashMap<>();
    count.put(0,1);
    int sum=0;
    int counter =0;
    for(int i=0;i<nums.length;i++){
        sum +=nums[i];
        if(count.containsKey(sum - k)){
            counter+=count.get(sum-k);
        }
        count.put(sum,count.getOrDefault(sum,0)+1);
    }
    return counter;
}
}