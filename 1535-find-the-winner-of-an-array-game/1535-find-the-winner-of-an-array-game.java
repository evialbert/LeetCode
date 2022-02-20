class Solution {
    public int getWinner(int[] arr, int k) {
        int n = arr.length;
        int m = 0;
        for (int nu:arr) {
            m = Math.max(m,nu);
        }
        if (k>=n) return m;
        int [] pq = new int[2];
        pq[0] = arr[0];
        int w = -1;
        int l = -1;
        int wc = 0;                
        int i = 0;
        int j = 1;
        while (wc<k) {
            pq[1] = arr[j];
            sortA(pq);
            l = pq[1];
            if (pq[0]!=w) {
                w = pq[0];
                wc = 1;
            } else {
                wc++;
            }
            arr[i] = l;
            j = (j+1)%n;
            i = (i+1)%n;
        }
        return w;
    }
    public void sortA(int[] a) {
        int x1 = a[0];
        int x2 = a[1];
        a[0] = Math.max(x1, x2);
        a[1] = Math.min(x1, x2);
    }
}