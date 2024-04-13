class Solution {
    public int minLengthAfterRemovals(List<Integer> nums) {
        int n=nums.size();
        if(n==1) return 1;
        int low=0;
        int high=n/2;
        int count=0;
        HashSet<Integer>hs=new HashSet<>();
        while(high<n){
            if(hs.contains(low)==false){
                if(nums.get(low)<nums.get(high)){
                    count+=2;
                    hs.add(high);
                    high++;
                    low++;
                }else{
                    high++;
                }
            }else{
                low++;
            }
        }
        return n-count;
    }
}