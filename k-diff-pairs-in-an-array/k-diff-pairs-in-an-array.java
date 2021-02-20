class Solution {
    public int findPairs(int[] nums, int k) {
        if(k<0 || nums==null){
            return 0;
        }
        
        HashMap<Integer,Integer> m = new HashMap<>();
        int count = 0;
        
        for(int num:nums){
            m.put(num,m.getOrDefault(num,0)+1);
        }
        
        for(Map.Entry<Integer,Integer> entry:m.entrySet()){
            if(0==k){
                if(entry.getValue()>1){
                    count++;
                }
            }else{
                if(m.containsKey(entry.getKey()+k)){
                    count++;
                }
            }
        }

        return count;
    }
}
