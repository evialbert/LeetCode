class Solution {
    public String mergeAlternately(String word1, String word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int n = l2 > l1 ? l2 : l1;
        char[] c = new char[l1+l2];
        int i = 0; int j = 0; int k = 0;
        while(i < l1 || j < l2){
            if(i < l1){
                c[k++] = word1.charAt(i++);
            }
            if(j < l2){
                c[k++] = word2.charAt(j++);
            }
        }
       
        return new String(c);
    }
}