/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var beautifulSubsets = function(nums, k) { 
    const dfs=(i,path)=>{
        if(i===nums.length) return 0;

        let subset=0;
        if(!path.has(nums[i]+k) && !path.has(nums[i]-k)){
            path.set(nums[i],path.get(nums[i])+1||1);
            subset+=dfs(i+1, path)+1;
            path.set(nums[i],path.get(nums[i])-1);
            if(path.get(nums[i])===0)
                path.delete(nums[i]);
        }
        subset+=dfs(i+1, path);
        return subset
    }
    return dfs(0,new Map());
};