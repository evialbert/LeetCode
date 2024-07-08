class Solution {
    public int maximumLength(int[] arr) {
        int diff[] = new int[2];
        int same[] = new int[2];

        int n = arr.length;
        for(int i=0; i<n; i++){
            int rem = arr[i]%2;

            same[rem] = same[rem]+1;
            diff[rem] = Math.max(diff[rem],1+diff[1^rem]);
        }

        return Math.max(Math.max(same[0],same[1]),Math.max(diff[0],diff[1]));
    }
}