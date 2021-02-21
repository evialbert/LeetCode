class Solution {
    public boolean isLongPressedName(String name, String typed) {
        if(name.length()>typed.length()) return false;
        int n = 0;
        int t = 0;
        int lenName = name.length();
        int lenTyped = typed.length();
        while(n<lenName && t<lenTyped){
            char c = name.charAt(n);
            if(c!=typed.charAt(t)) return false;
            int countInName = 0;
            int countInTyped = 0;
            while(n<lenName && name.charAt(n)==c){
                n++;
                countInName++;
            }
            while(t<lenTyped && typed.charAt(t)==c){
                t++;
                countInTyped++;
            }
            if(countInName>countInTyped) return false;
            
        }
    
        if(n==lenName && t==lenTyped) return true;
        return false;
    }
}