class Solution {
    public long numberOfWeeks(int[] milestones) {
     long ans=0;
    int max=Integer.MIN_VALUE;
    for(int i:milestones)
    {
        ans+=i;
        max=Math.max(max,i);
    }
    ans-=max;
    ans+=Math.min(ans+1,max);
    return ans;
    
}    
    
}