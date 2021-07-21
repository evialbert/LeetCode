class Solution {
    public String decodeAtIndex(String str, int k) {
        long size =0 ;
        for(int i=0;i<str.length();i++) {
            char ch=str.charAt(i);
            if(Character.isDigit(ch)) {
                size*=ch-'0';
            } else {
                size++;
            }
        }
        
       for (int i = str.length()-1; i >= 0; --i) {
            char c = str.charAt(i);
            if (Character.isDigit(c)) {
                size /= c - '0';
                k %= size;
            } else {
                if(k==0 || k==size) {
                    return Character.toString(c);
                }
                size--;
            }
                
        }
        return "";
    }
}