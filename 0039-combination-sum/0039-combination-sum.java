class Solution {
    List<List<Integer>> resList=new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> sublist=new ArrayList<>();
        helper(candidates,target,sublist,0);
        return resList;
    }
    public void helper(int[] arr,int target,List<Integer> sublist,int start){
        if(target==0){
            resList.add(new ArrayList<>(sublist));
        }else if(target>0){
        for(int i=start;i<arr.length;i++){
            sublist.add(arr[i]);
            helper(arr,target-arr[i],sublist,i);
            sublist.remove(sublist.size()-1);
        }
        }
    }
}