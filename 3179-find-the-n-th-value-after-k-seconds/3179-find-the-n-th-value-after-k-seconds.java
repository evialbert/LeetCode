class Solution {
    public int valueAfterKSeconds(int n, int k) {
        long[] a = new long[n];
        for(int i=0;i<n;i++)
            a[i]=1;
        int time =0;
        while(time<k){
            for(int i=1;i<n;i++)
                a[i] = (a[i-1] + a[i])%((int)1e9 + 7);
            time++;
        }
        return (int)(a[n-1]%((int)1e9 + 7));
        
    }
}