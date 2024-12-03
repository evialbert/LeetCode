class Solution {
    public int getLargestOutlier(int[] nums) {
        int result=Integer.MIN_VALUE;
        int sum=0;
        HashMap<Integer,Integer> h=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++)
            {
                if(!h.containsKey(nums[i]))
                {
                     h.put(nums[i],1);
                }
                else
                {
                    h.put(nums[i],h.get(nums[i])+1);
                }
                sum+=nums[i];
            }
       for(int i=0;i<nums.length;i++)
           {
                  int y=sum-(2*nums[i]);
                  if(h.containsKey(y))
                  {
                      if(y!=nums[i])
                      {
                      result=Math.max(result,y);
                      }
                      else
                      {
                          if(h.get(y)>1)
                          {
                               result=Math.max(result,y);
                          }
                      }
                  }
           }

        return result;
        
    }
}