//binary search
class Solution {
    public void wiggleSort(int[] nums) {
        var mid=findMid(nums);
        
        int ltc=(nums.length+1)/2;
        List<Integer> lt=new ArrayList<>(),gt=new ArrayList<>();
        for(int num:nums) {
            if(num<mid) lt.add(num);
            else if(num>mid) gt.add(num);
        }
        
        int lc=lt.size(),gc=gt.size();
        
        for(int i=0;i<nums.length;i++) {
            if(i%2==0) {
                if(ltc-->lc) {
                    // position is more than small number counts, use mid first
                    nums[i]=mid;
                } else {
					// use any small number
                    nums[i]=lt.get(--lc);
                }
            } else if (gc>0) {
				// use any big number
                nums[i]=gt.get(--gc);
            } else {
				// no more big numbers, start to use mid
                nums[i]=mid;
            }
        }
    }
    
    int findMid(int[] nums) {
        int min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        for(int num:nums) {
            min=Math.min(num,min);
            max=Math.max(num,max);
        }
        var half=nums.length/2;
        while(min<max) {
            int ec=0,gc=0;
            var mid=(min+max)/2;
            
            for(int num:nums) {
                if(num>mid) gc++;
                else if(num==mid) ec++;
            }
            
            if(gc<=half&&gc+ec>=half) return mid;
            // too small
            if(gc>half) min=mid+1;
            else max=mid-1;
        }
        
        return min;
    }
    
}