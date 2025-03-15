class Solution {
    public int minCapability(int[] a, int k) {
        int b[]=Arrays.copyOf(a,a.length);
        Arrays.sort(b);
        int l=b[0],r=b[a.length-1],mid,ans=r;

        while(l<=r)
        {
            mid=l+(r-l)/2;
            int x=robbinghouses(a,mid,k);
            if(x>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
    public int robbinghouses(int[] a,int val,int k)
    {
        int i,count=0;
        for(i=0;i<a.length;)
        {
            if(a[i]<=val)
            {
            count++;
            i+=2;
            }
            else
            i++;
        }
        return count;
    }
}