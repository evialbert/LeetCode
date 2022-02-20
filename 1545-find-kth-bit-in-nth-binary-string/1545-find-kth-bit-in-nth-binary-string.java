//Java recursive easy
class Solution {
    public char findKthBit(int n, int k) {
        return rec(n).charAt(k-1);
    }
    
	
    public String rec(int n) {
        if (n == 1){ 
            return "0";
        } else {
            String s = rec(n-1);
            return s + "1" + reverse_and_invert(s);
        }
    }
    
	
    public String reverse_and_invert(String s) {
        char[] c = s.toCharArray();
        
        int i = 0;
        int j = c.length-1;
        
        while(i < j) {
            Character temp = c[i];
            c[i] = c[j] == '0' ? '1' : '0';
            c[j] = temp == '0' ? '1': '0';
            
            i++;
            j--;
        }
        
        if (c.length % 2 == 1) {
            c[i] = c[i] == '0' ? '1' : '0';
        }
        
        return String.valueOf(c);
    }
    
}