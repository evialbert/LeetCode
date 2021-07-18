class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        int n = A.length;
        int m = B.length;
        if (n != m) {
            throw new IllegalArgumentException("the inputs have different lengths.");
        }
        
        TreeMap<Integer, Integer> counts = new TreeMap<>();
        for (int num : A) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            Integer cur = counts.higherKey(B[i]);
            if (cur == null) {
                cur = counts.firstKey();
            }
            
            ans[i] = cur;
            
            if (counts.get(cur) == 1) {
                counts.remove(cur);
            } else {
                counts.put(cur, counts.get(cur) - 1);
            }
        }
        
        return ans;
    }
}