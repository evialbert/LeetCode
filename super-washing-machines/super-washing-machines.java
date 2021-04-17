class Solution {
    public int findMinMoves(int[] a) {
        int sum=0;
        int n=a.length;
        for(int i=0;i<n;i++)
            sum+=a[i];
        if(sum%n!=0)
            return -1;
        sum=sum/n;
        int max=0;
        int cur_trans=0,prev_trans=0;
        int tot_trans=0;
        for(int i=0;i<n;i++)
        {
            cur_trans+=a[i]-sum;
            if(cur_trans>=0 && prev_trans>=0)
              tot_trans=cur_trans+prev_trans;
            else
                tot_trans=Math.max(Math.abs(cur_trans),Math.abs(prev_trans));
            max=Math.max(max,tot_trans);
            prev_trans=-cur_trans;
        }
        return max;
    }
}