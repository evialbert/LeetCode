class Solution {
    public int numSpecialEquivGroups(String[] A) {
        HashSet<String> set = new HashSet<String>();
        int len = A.length;
        for(int i=0;i<len;i++){
            int[] a = new int[52];
            String x = A[i];
            int len1 = x.length();
            for(int j=0;j<len1;j++){
                a[x.charAt(j)-'a'+26*(j%2)]++;
            }
            set.add(Arrays.toString(a));

        }
        return set.size();
    }

}