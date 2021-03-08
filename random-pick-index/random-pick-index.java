class Solution {

    public Random r;
    public HashMap <Integer, ArrayList <Integer>> map;
    
    public Solution (int[] nums) {
        map = new HashMap ();
        r = new Random ();
        for (int i = 0; i < nums.length; i++) {
            ArrayList <Integer> list = new ArrayList ();
            if (map.containsKey (nums [i]))
                list = map.get (nums [i]);
            list.add (i);
            map.put (nums [i], list);
        }
    }
    
    public int pick (int target) {
        ArrayList <Integer> list = map.get (target);
        return list.get (r.nextInt (list.size()));
    }
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */