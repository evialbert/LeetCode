class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans=new ArrayList<>();
        int i=1,idx=0;
        while(i<=n && idx<target.length){
            ans.add("Push");
            if(i==target[idx]){
                idx++;
            }else{
                ans.add("Pop");
            }
            i++;
        }
        return ans;
    }
}