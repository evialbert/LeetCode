class Solution {
    
    public boolean hasAllCodes(String s, int k) {
        
        if(k > s.length()) return false;
        int hash = 0;
        int count = 0;
        int maxValue = (1 << k) - 1;
        for(int i=0;i<k;i++){
            hash = hash + (s.charAt(i)-'0')* (1 << (k-i-1));
        }
        byte[] set = new byte[maxValue+1];
        
        set[hash] = 1;
        for(int i=k;i<s.length();i++){
            hash = 2 * hash - ((s.charAt(i-k) -'0') * (1 << k)) + s.charAt(i) - '0';
            set[hash] = 1;
        }
        
        for(int i=0;i<=maxValue;i++){
            if(set[i] == 0) return false;
        }
        return true;
    }
}