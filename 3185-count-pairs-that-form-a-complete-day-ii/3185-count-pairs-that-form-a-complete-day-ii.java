class Solution {
    public long countCompleteDayPairs(int[] hours) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        long ans = 0;
        for (int i=0;i<hours.length;i++) {
            int num = hours[i];
            int mod = num % 24;
            int rem = (24 - mod) % 24;
            ans += mp.getOrDefault(rem, 0);
            mp.put(mod, mp.getOrDefault(mod, 0) + 1);
        }
        return ans;
    }
}