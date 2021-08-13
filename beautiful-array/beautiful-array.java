class Solution {
    public int[] beautifulArray(int n) {
        int m = n/2 + n%2;
        int[] buf = new int[n];
        for(int i=1;i<=n;i+=2)
            buf[i/2] = i;
        for(int i=2;i<=n;i+=2)
            buf[m + i/2 -1] = i;
        //1,3,5,7,9,  2,4,6,8,10
        recOdd(buf,0,m-1);
        recEven(buf,m, n-1);
        return buf;
    }
    private void recOdd(int[] buf, int from, int to){
        if(from <0 || from>=to || to>=buf.length)
            return;
        for(int f=from;f<=to;f++)
            buf[f]++;
        recEven(buf,from, to);
        for(int f=from;f<=to;f++)
            buf[f]--;
        
    }
    private void recEven(int[] buf, int from, int to){
        if(from <0 || from>=to || to>=buf.length)
            return;

        for(int i=from;i<=to;i++)
            buf[i]/=2;

        int f = from, t = to;
        while(f<t){
            while(f < t && buf[f]%2==1) 
                f++;
            while(f < t && buf[t]%2==0)
                t--;
            if(f < t){
                int temp = buf[f];
                buf[f]=buf[t];
                buf[t] = temp;
            }

        }
        recOdd(buf, from, f+buf[f]%2-1);
        recEven(buf, f+buf[f]%2, to);

        for(int i=from;i<=to;i++)
            buf[i]*=2;
    }
}