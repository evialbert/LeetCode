class Solution {
    public int maximumLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int res = 1;
        boolean flag = false;
        
        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);
        
        for (int key : map.keySet()) {
            if (key == 1) {
                flag = true;
                continue;
            }
            int num = key;
            int cnt = 0;
            int i = 1;
            while (map.getOrDefault((int)Math.pow(num, i), 0) >= 2) {
                i *= 2;
                cnt += 2;
            }
            if (map.getOrDefault((int)Math.pow(num, i), 0) == 1) {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            res = Math.max(res, cnt);
        }
        
        if (flag) {
            int cnt = map.get(1);
            if (cnt % 2 == 0) cnt --;
            res = Math.max(res, cnt);
        }
        return res;        
    }
}