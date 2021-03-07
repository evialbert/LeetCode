class Solution {

private int[] original;
private int[] shuffled;
public Solution(int[] nums) {
  original = Arrays.copyOf(nums,nums.length);  
  shuffled = Arrays.copyOf(nums,nums.length);  
}

/** Resets the array to its original configuration and return it. */
public int[] reset() {
    return original;
}

/** Returns a random shuffling of the array. */
public int[] shuffle() {
    
    int max = shuffled.length-1;
    int min = 0;
    int range = max - min + 1;
    
    int r = (int)(Math.random()*range+min);
    for(int i = 0; i<=max; i++){
        if(r != i){
            swap(shuffled,r,i);
            break;
        }
    }
     
    return shuffled;
}

public void swap(int[] nums, int i , int j){  
    int temp = nums[i];
    nums[i]  = nums[j];
    nums[j]  = temp;
}
}

/**

Your Solution object will be instantiated and called as such:
Solution obj = new Solution(nums);
int[] param_1 = obj.reset();
int[] param_2 = obj.shuffle();
*/