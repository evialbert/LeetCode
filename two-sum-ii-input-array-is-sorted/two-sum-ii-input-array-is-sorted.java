class Solution {
   public int[] twoSum(int[] numbers, int target) {
        int sum =0;
        int[] res = new int[2];
    
        for(int i = 0 ; i<numbers.length ; i++){
            for(int j=i+1; j<numbers.length; j++){
                sum = numbers[i] + numbers[j];
                if (sum==target){
                    res[0]=i+1;
                    res[1]=j+1;
                break;
                }
            }
        }
        
        return res;
        
    }

}