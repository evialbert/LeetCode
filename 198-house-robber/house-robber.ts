function rob(nums: number[]): number {
    let n=nums.length;

    if(n<=3){
        if(n==2)
            return Math.max(nums[0], nums[1]);
        if(n==1)
            return nums[0];
        if(n==3)
            return Math.max(nums[0]+nums[2], nums[1]);
    }

    for(let i=n-3;i>=0;i--){
        let f=nums[i+2]??0;
        let s=nums[i+3]??0;
        nums[i]=nums[i]+Math.max(f, s);
    }
    return Math.max(nums[0], nums[1]);
};