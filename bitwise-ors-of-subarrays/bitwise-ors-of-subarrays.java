class Solution {
   public int subarrayBitwiseORs(int[] arr) {
        HashSet<Integer> res = new HashSet<>();
        HashSet<Integer> prev = new HashSet<>();
        
        for(int num: arr) {
            HashSet<Integer> cur = new HashSet<>();
            cur.add(num);
            for(int prevNum: prev) cur.add(num | prevNum);
            prev = cur;
            res.addAll(cur);
        }
        
        return res.size();
    }
}
