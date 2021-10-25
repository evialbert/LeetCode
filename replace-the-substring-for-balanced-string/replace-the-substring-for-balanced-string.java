class Solution {
    public int balancedString(String s) {
        int required = s.length() / 4, answer = s.length();
        int[] arr = new int[4];
        
        for (int i = 0; i < s.length(); i++) {
            arr[getIndex(s.charAt(i))]++;
        }
        
        int l = 0, r = 0;
        while (r < s.length()) {
            for (int j = 0; j < 4; j++) {
                while (r < s.length() && arr[j] > required) {
                    arr[getIndex(s.charAt(r++))]--;
                }
            }
            
            if (l < r) {
                do {
                    answer = Math.min(answer, r - l);
                    arr[getIndex(s.charAt(l++))]++;
                } while (arr[0] <= required && arr[1] <= required && arr[2] <= required && arr[3] <= required && l < r);
            } else {
                answer = Math.min(answer, r - l);
                r++;
            }
        }
        
        return answer;
    }
    
    private int getIndex(char cur) {
        switch (cur) {
            case 'Q': return 0;
            case 'W': return 1;
            case 'E': return 2;
            case 'R': return 3;
        }
        
        throw new IllegalArgumentException();
    }
}