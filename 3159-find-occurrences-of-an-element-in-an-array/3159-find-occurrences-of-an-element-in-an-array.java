class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        int ans[] = new int[queries.length];
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < nums.length ; i++){
            if(nums[i] == x){
                list.add(i);
            }
        }
        int countOfx = 0;
        for(int i : nums){
            if(i == x)countOfx++;
        }
        int ansidx = 0;
        int listidx = 0;
        for(int i : queries){
            if(countOfx >= i){
                ans[ansidx++] = list.get(i-1);
            }else{
                ans[ansidx++] = -1;
            }
        }
        return ans;
    }
}