class Solution {
   public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList();
        combinations(res, new ArrayList<Integer>(), 1, n, k);
        return res;
    }
    private void combinations(List<List<Integer>> res, List<Integer> temp, int start, int end, int k){
        if(k == 0){
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        for(int i=start; i<=end-k+1; i++){
            temp.add(i);
            combinations(res, temp, i+1, end, k-1);
            temp.remove(temp.size()-1);
        }
    }
}