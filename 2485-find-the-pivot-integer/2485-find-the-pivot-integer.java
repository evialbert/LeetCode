class Solution {
    public int pivotInteger(int n) {
        int left=1;
        int right=n;

        int leftSum=left;
        int rightSum=right;
        
        for(int i=1; left <= right; i++){
            if(leftSum == rightSum && left == right)   return left;
            
            else if(leftSum < rightSum){
                left += 1;
                leftSum += left;
            } else {
                right -= 1;
                rightSum += right;
            }
        }
        return -1;
    }
}