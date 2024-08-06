class Solution {
    public int minChanges(int n, int k) {
        String nb = Integer.toBinaryString(n);
        String kb = Integer.toBinaryString(k);
        
        if (nb.length() < kb.length())
            return -1;
        
        int ans = 0;
        int diff = nb.length() - kb.length();
        
        for (int i = 0; i < diff; i++) {
            if (nb.charAt(i) == '1')
                ans++;
        }
        
        for (int i = 0; i < kb.length(); i++) {
            if ((nb.charAt(i+diff) == '1') && (kb.charAt(i) == '0'))
                ans++;
            else if  ((nb.charAt(i+diff) == '0') && (kb.charAt(i) == '1'))
                return -1;
        }
        return ans;
    }
}