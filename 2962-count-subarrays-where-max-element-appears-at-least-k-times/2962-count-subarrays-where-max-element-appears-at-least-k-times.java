class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n=nums.length;
        int max=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max)
                max=nums[i];
        }
        List<Integer> l=new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==max)
            {
                l.add(i);
            }
        }
        int rep=l.size();
        if(rep<k)
            return 0;
        long tot=0;
        long temp=0;
        int x=0;
        System.out.println(l);
        for(int i=0;i+k-1<rep;i++)
        {
            temp=0;
            temp++;
            long left=l.get(i)-x;
            long right=n-l.get(i+k-1)-1;
            temp+=left;
            temp+=right;
            temp+=left*right;
            x=l.get(i)+1;
            tot=tot+temp;
            System.out.println(" left : "+left +" right : "+right +"  total : "+tot);
        }
        return tot;
    }
}