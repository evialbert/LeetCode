class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> al1 = new ArrayList<>();
        List<Integer> al2 = new ArrayList<>();
       
        al1.add(nums[0]);
        al2.add(nums[1]);
        
        int lastinsert1 = nums[0];
        int lastinsert2 = nums[1];
        for(int i=2;i<nums.length;i++){
            if(lastinsert1 > lastinsert2){
                al1.add(nums[i]);
                lastinsert1 = nums[i];
            }else{
                 al2.add(nums[i]);
                lastinsert2 = nums[i]; 
            }
        }
        int res[] = new int[al1.size()+al2.size()];
        int i=0;
        for(int al:al1){
            res[i++] = al;
        }
        
         for(int al:al2){
            res[i++] = al;
        }
        
        
        return res;
    }
}