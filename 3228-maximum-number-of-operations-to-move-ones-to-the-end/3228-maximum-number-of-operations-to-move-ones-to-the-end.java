class Solution {
    public int maxOperations(String s) {
        char[] arr = s.toCharArray();
        int one = arr[0] - '0';
        int res = 0;
        for(int i = 1; i < arr.length; i++) {
            one += arr[i] - '0';
            res += arr[i - 1] > arr[i] ? one : 0;
        }
        return res;
    }
}