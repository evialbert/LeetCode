class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        boolean swapped = false; int bad = 0;
        char[] missing = new char[26];
        
        if(s1.length() != s2.length()) return false;
        
        for(int i = 0; i < s1.length(); i++){
            if(s1.charAt(i) != s2.charAt(i)){
                char temp = missing[s2.charAt(i)-'a'];
                if(bad == 0){
                    missing[s1.charAt(i)-'a'] = s2.charAt(i);
                    bad++;
                }
                else if(swapped || missing[s2.charAt(i)-'a']!=s1.charAt(i)) return false;
                else swapped = true;
            }
        }
        return bad==0 || swapped;
    }
}