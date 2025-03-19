function minOperations(nums: number[]): number {

    let count =0;
    let k =3;
    let right = 0;
    let high = nums.length;

    while(right < high-k+1){

        if(nums[right] ==0){
            count++;
            nums[right] = 1;
            nums[right+1] = nums[right+1] ==0? 1:0;
            nums[right+2] = nums[right+2] ==0? 1:0;
        } else {
            right++;
        }
    }

    if(nums[high-1] == 0 || nums[high-2] == 0 || nums[high-3]== 0){
        return -1;
    }


    return count;
};