class Solution {
    public int largestInteger(int[] nums, int k) {
        int left = 0;
        int curMax = -1;
        if(nums.length==k)
        {
            for(int i : nums)
            {
                curMax = Math.max(curMax,i);
            }
            return curMax;
        }
        ArrayList<Integer> list = new ArrayList<>();
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<k;i++)
        {
            list.add(nums[i]);
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
        }

        for(int i=k;i<nums.length;i++)
        {
            list.remove(0);
            list.add(nums[i]);
            for(int val : list)
            {
                map.put(val,map.getOrDefault(val,0)+1);
            }
        }
        int max =-1;
        for(int i : nums)
        {
            if(map.get(i)==1)
            {
                max = Math.max(max,i);
            }
        }
        return max;
        
    }
}