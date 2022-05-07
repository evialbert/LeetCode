class Solution {
    public String maximumBinaryString(String binary) {
        int len = binary.length(), l = 0, r = len-1;
        char[] arr = binary.toCharArray();
        while (l<len && arr[l]=='1') l++;
        while (r>=0 && arr[r]=='1') r--;
        if (l<r) {
            int ones = 0;
            for (int i = l; i<=r; i++) {
                ones += arr[i]=='1' ? 1 : 0;  
            }
            Arrays.fill(arr, r-ones, r+1, '1');
            Arrays.fill(arr, 0, r-ones, '1');
            arr[r-ones] = '0';
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i<len; i++) {
            sb.append(arr[i]);
        }
        return sb.toString();
    }
}