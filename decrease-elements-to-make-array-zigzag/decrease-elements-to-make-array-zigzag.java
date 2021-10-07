class Solution {
    public int movesToMakeZigzag(int[] a) {
        int n=a.length;
        
        int even[]=Arrays.copyOf(a,n);
        int evenReduce=0;
        for(int i=0;i<n;i+=2)
        {
            if(i!=0 && even[i]<=even[i-1])
            {
                evenReduce+=even[i-1]-even[i]+1;
                even[i-1]=even[i]-1;
            }
            if(i!=n-1 && even[i]<=even[i+1])
            {
                evenReduce+=even[i+1]-even[i]+1;
                even[i+1]=even[i]-1;
            }
        }
        
        int odd[]=Arrays.copyOf(a,n);
        int oddReduce=0;
        for(int i=1;i<n;i+=2)
        {
            if(i!=0 && odd[i]<=odd[i-1])
            {
                oddReduce+=odd[i-1]-odd[i]+1;
                odd[i-1]=odd[i]-1;
            }
            if(i!=n-1 && odd[i]<=odd[i+1])
            {
                oddReduce+=odd[i+1]-odd[i]+1;
                odd[i+1]=odd[i]-1;
            }
        }
        
        return Math.min(evenReduce,oddReduce);
    }
}