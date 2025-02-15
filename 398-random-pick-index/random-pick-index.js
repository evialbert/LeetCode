/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
   this.nums = nums;
   this.length = nums.length;
};

Solution.prototype.pick = function(target) {
    var numsArray = this.nums;
    var numsLength = this.length;
    
    if(numsLength == 1) return 0;
       
    var output = 0;
    var count = 0;
  
    
    for(var i=0; i < numsLength; i++){
        if(numsArray[i] == target && Math.floor(Math.random() * (++count)) == 0){
              output = i;
         }
    }
    
    return output;
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.pick(target)
 */