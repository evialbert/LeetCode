class Solution {
   public int[] constructArray(int n, int k) {
        int a[] = new int[n];
        boolean b[] = new boolean[n];
        Arrays.fill(b, true);
        int first = 1;
        a[0] = 1;
        b[0] = false;
        int i=1;
        while(k != 0) {
            if(i%2 != 0) {
                a[i] = a[i-1] + k;
                b[a[i]-1] = false;
            } else {
                a[i] = a[i-1] - k;
                b[a[i]-1] = false;
            }
            k--;
            i++;
        }
        int t = n-1;
        for(i=n-1; i>=0; i--) {
            if(b[i]) {
                a[t--] = i+1;
            }
        }
        return a;
    }
}
