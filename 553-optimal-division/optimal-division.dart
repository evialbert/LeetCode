class Solution {
  String optimalDivision(List<int> nums) {
    String a = nums[0].toString();
    String b = '';
    for(int i = 1; i < nums.length; i++){
        if(i == 1 && nums.length > 2){
            b += '/(' + nums[i].toString();
        }
        else{
            b += '/' + nums[i].toString();
        }
        if(i == nums.length-1 && nums.length > 2){
            b += ')';
        }
    }
    return a+b;
  }
}