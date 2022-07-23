class Solution {
    public String toLowerCase(String s) {
        int diff = 'A'-'a';
        char[] c = s.toCharArray();
        for(int i=0; i<c.length; i++){
            if(c[i]>='A' && c[i]<='Z'){
                c[i]-=diff;
            }
        }
        return new String(c);
    }
}