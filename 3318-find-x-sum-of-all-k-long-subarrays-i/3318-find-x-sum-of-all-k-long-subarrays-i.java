class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int y = 0;
        for (int i = 0; i < ans.length; i++) {
            int count = 0;
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int j = i; j < i + k; j++) {
                map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            }
            HashSet<Integer> set = new HashSet<>();
            for (int j = 0; j < x; j++) {
                int max = 0;
                int getdata = 0;
                for (int key : map.keySet()) {
                    if (map.get(key) > getdata && !set.contains(key)) {
                        getdata = map.get(key);
                        max = key;
                    }
                }
                for(int key : map.keySet()) if(map.get(key)==getdata) max = Math.max(max,key);
                map.remove(max, getdata);
                count += (max * getdata);
            }
            ans[y] = count;
            y++;
        }
        return ans;
    }
}