class Solution {
    public int minFlips(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length, c1 = 0, c0 = 0;
        if(n < 3) return 0;
        for(int i = 1; i < n - 1; i++) {
            if(arr[i] == '1') c1++;
            else c0++;
        }
        if(arr[0] == '1' && arr[n - 1] == '1') {
            return Math.min(c1, c0);
        }
        if(arr[0] == '1') c1++;
        else c0++;
        if(arr[n - 1] == '0') c0++;
        else c1++;
        if(c1 < 2) return 0;
        return Math.min(c1 - 1, c0);
    }
}