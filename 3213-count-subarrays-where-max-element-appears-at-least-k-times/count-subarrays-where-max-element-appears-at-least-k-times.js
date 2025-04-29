/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let maxi=Math.max(...nums);
    let cnt=0,left=0,freq=0;
    for(let right=0;right<nums.length;right++){
      if(nums[right] === maxi)cnt++;

      while(cnt>=k){
          if(nums[left] === maxi)cnt--;
            left++;
          
      }
       freq+=left;
    }
    return freq;
};