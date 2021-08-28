class Solution {
    int res;
    public boolean isPerfectSquare(int a,int b){
        double sqrt = Math.sqrt(a+b);
        return sqrt - (int)sqrt == 0;
    }
    public void helper(boolean[] visited,int[] nums){
        for(int i = 0;i<nums.length;i++){
            if(i == 0 || nums[i] != nums[i-1]){
                visited[i] = true;
                dfs(visited,nums,1,nums[i]);
                visited[i] = false;
            }
        }
    }
    public void dfs(boolean[] visited,int[] nums,int count,int last){
        if(count == nums.length){
            res++;
            return;
        }
        for(int i = 0;i<nums.length;i++){
            if(!visited[i] && (i == 0 || visited[i-1] || (nums[i-1] != nums[i])) && isPerfectSquare(last,nums[i])){
                visited[i] = true;
                dfs(visited,nums,count+1,nums[i]);
                visited[i] =  false;
            }
        }
    }
    public int numSquarefulPerms(int[] nums) {
        res = 0;
        int n = nums.length;
        if(n == 1)
            return 0;
        Arrays.sort(nums);
        boolean[] visited = new boolean[n];
        helper(visited,nums);
        return res;
    }
}