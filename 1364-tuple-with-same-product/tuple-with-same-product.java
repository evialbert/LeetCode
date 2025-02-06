class Solution {
    public int tupleSameProduct(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();
        int n=nums.length;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p=nums[i]*nums[j];
                map.put(p,map.getOrDefault(p,0)+1);
            }
        }
        for(Map.Entry<Integer,Integer> entry:map.entrySet()){
            int a=entry.getValue();
            
            int b=(a*(a-1))/2;
            count+=(b*8);
            
        }
        return count;
        
    }
}