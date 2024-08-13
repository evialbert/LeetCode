class Solution {
    public static void sum(int[] arr, int ind, int target, List<List<Integer>> list, List<Integer> ds){
      if(target==0){
          list.add(new ArrayList<>(ds));
       return;
      }
      for(int i=ind; i<arr.length;i++){
          if(i>ind && arr[i]==arr[i-1])continue;
          if(arr[i]>target)break;
        
        ds.add(arr[i]);
        sum(arr,i+1,target-arr[i],list,ds);
        ds.remove(ds.size()-1);
      }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans= new ArrayList<>();
        Arrays.sort(candidates);
        sum(candidates,0,target,ans,new ArrayList<>());
        return ans;
    }
}