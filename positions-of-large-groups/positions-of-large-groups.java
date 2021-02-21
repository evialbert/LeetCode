class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        int start = 0;
        int end = 0;
        List<List<Integer>> ans = new ArrayList();
        for(int i = 1; i < S.length(); i++){
            if(S.charAt(i-1)==S.charAt(i)){
                end = i;
            }else{
                if(end-start>=2){
                    ans.add(Arrays.asList(new Integer[]{start, end}));
                }
                start = i;
            }
        }
        if(end-start>=2){
            ans.add(Arrays.asList(new Integer[]{start, end}));
        }
        return ans;
    }
}