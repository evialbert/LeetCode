class Solution {
    public int countSpecialSubsequences(int[] nums) {
        long count0=0, count1=0, count2 =0;
        long mod = 1000000007;
        
        
        for(int n:nums){
            
            if(n==0){
                
                count0=(count0*2+1)%mod;
                
            }
            else if(n==1){
                
                count1 = (count1*2+count0)%mod;
                
            }
            else{
                
                count2 = (count2*2+count1)%mod;
                
            }
            // System.out.println("count0:"+count0+" count1:"+count1+" count2:"+count2);
        }
        
        return (int)count2;
        
    }
}
