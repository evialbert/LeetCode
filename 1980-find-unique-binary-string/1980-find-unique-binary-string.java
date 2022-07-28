class Solution {
    String ans ;
    public String findDifferentBinaryString(String[] nums) {
        List<String> list = new ArrayList<>() ;
        for(String el : nums)list.add(el) ;
        int length = nums[0].length() ;
        rec(new StringBuilder() , list , length) ;    
        return ans ;
    }
    public void rec(StringBuilder op , List<String> list , int len){
        if(op.length()>len)return;

        if(!list.contains(op.toString()) && op.length()==len){
            ans = op.toString() ;
            return ;
        }
        op.append(1) ;
        rec(op,list,len) ;
        op.deleteCharAt(op.length()-1) ;
        op.append(0) ;
        rec(op,list,len) ;
        op.deleteCharAt(op.length()-1) ;
    }
    
}