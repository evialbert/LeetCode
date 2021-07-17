class Solution {
    public int numSimilarGroups(String[] strs) {
        // group count; initially all strings are in independent groups
        int gc = strs.length; 
        int[] group = new int[strs.length];
        for (int i=0; i<group.length; i++) {
            group[i] = i; // parent
        }
        // check each pair
        for (int i=0; i<strs.length-1; i++) {
            for (int j=i+1; j<strs.length; j++) {
                if (similar(strs[i], strs[j])) {
                    // connect them
                    if (connect(i, j, group)) --gc;
                }
            }
        }
       
        return gc;
    }
    
    // returns false if i & j were already connected
    private boolean connect(int i, int j,int[] group) {
        int p1 = parent(i, group);
        int p2 = parent(j, group);
        if (p1 == p2) return false; // already connected
        group[p2] = p1;
        return true; 
    }
    
    private int parent(int i, int[] group) {
        if (group[i] == i) return i;
        int pi = parent(group[i], group);
        group[i] = pi; // compress
        return pi;
    }
    
    
    private boolean similar(String s1, String s2) {
        int count = 0;
        for (int i=0; i<s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) ++count;
            if (count > 2) return false;
        }
        return true;
    }
}