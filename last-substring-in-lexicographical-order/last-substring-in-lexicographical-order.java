class Solution {
    public String lastSubstring(String s) {
        char largestChar = 'a';
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) > largestChar) {
                largestChar = s.charAt(i);
            }
        }
        
        int largestIndex = -1; // starting point of the current largest substring
        int i = 0;
        while ( i < s.length() ) {
            if (s.charAt(i) == largestChar) {
                if (largestIndex == -1) {
                    largestIndex = i;
                    i++;
                }
                else {
                    int a = i;
                    int b = largestIndex;
                    int jumpIndex = -1;
                    // skip a good number of comparison which won't be greater than indices.get(j)
                    while (a < s.length() && s.charAt(a) == s.charAt(b)) {
                        if (s.charAt(a) != largestChar) jumpIndex = a;
                        a++;
                        b++;
                    }
                    if (jumpIndex == -1) jumpIndex = a;
                    if (a < s.length() && s.charAt(a) > s.charAt(b)) largestIndex = i;
                    i = jumpIndex;
                }
            }
            else i++;
        }
        return s.substring(largestIndex);
    }
}