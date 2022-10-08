class Solution {
   public boolean isSameAfterReversals(int num) {
    
    if(num == 0){
        return true;
    }
    
    if(Integer.toString(num).charAt(Integer.toString(num).length() - 1) == '0'){
        return false;
    }else{
        return true;
    }
}
}