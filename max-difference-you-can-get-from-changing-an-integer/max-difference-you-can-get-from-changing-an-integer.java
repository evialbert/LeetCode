class Solution {
    public int maxDiff(int num) {
        String str = String.valueOf(num);
        return max(str.toCharArray()) - min(str.toCharArray());
    }
    
    private int max(char[] C) {
        char from = C[0];
        char to = '9';
        
        if (C[0] == '9') {
            // Instead of replace '9' with '9', if possible, replace a lower weight with 9.
            for (int i = 1; i < C.length; i++) {
                if (C[i] != '9') {
                    from = C[i];
                    break;
                }
            }
        }
        
        return replace(C, from, to);
    }
    
    private int min(char[] C) {
        char from = C[0];
        char to = '1';
        
        if (C[0] == '1') {
            // Instead of replace '1' with '1', if possible, replace a lower weight with 0.
            for (int i = 1; i < C.length; i++) {
                if (C[i] > '1') {
                    from = C[i];
                    to = '0';
                    break;
                }
            }
        }
        
        return replace(C, from, to);
    }
    
    private int replace(char[] C, char from, char to) {
        for (int i = 0; i < C.length; i++) {
            if (C[i] == from) C[i] = to;
        }
        String str = new String(C);
        return Integer.parseInt(str);
    }
}