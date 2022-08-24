class Solution {
    public int numOfPairs(String[] nums, String target) {
        int ans=0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                String s=nums[i].concat(nums[j]);
                String s2=nums[j].concat(nums[i]);
                if(isEquals(s,target) && isEquals(s2,target)){
                    ans+=2;
                    continue;
                }else if(isEquals(s,target)){
                    ans++;
                    continue;
                }else if(isEquals(s2,target)){
                    ans++;
                }
            }
        }
        return ans;
    }
    public boolean isEquals(String s,String target){
        if(s.equals(target)){
            return true;
        }
        return false;
    }
}