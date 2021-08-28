class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int left = 0;
        int ans = 0;
        for(int right = 0; right < nums.length; right++){
            map.put(nums[right], map.getOrDefault(nums[right],0) + 1);
            while(map.size() > k){
                if(map.get(nums[left]) == 1){
                    map.remove(nums[left]);
                }else{
                    map.put(nums[left], map.get(nums[left])-1);
                }
                left++;
            }

            if(map.size() == k){
                int a = left;
                int b = right;
                HashMap<Integer,Integer> check = new HashMap<Integer,Integer>();
                ans++;
                while(a <= b){
                    check.put(nums[a], check.getOrDefault(nums[a],0)+1);
                    if(map.get(nums[a]) - check.get(nums[a]) > 0){
                        ans++;
                    }else{
                        break;
                    }
                    a++;
                }
            } 
        }
        return ans;
    }
}