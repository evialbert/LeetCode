class Solution {
   public int[] numsSameConsecDiff(int n, int k) {

        List<Integer> result = new ArrayList<>();
       
        for(int i = 1;i <= 9; i++){
            backtrack(result, i,n , k, i, 1);
        }
        return  result.stream().mapToInt(i->i).toArray();
    }

    public void backtrack(List<Integer> result, int val, int n , int k, int lastval, int count){

        if(count == n){
            result.add(val);
            return;
        }
       int i = lastval - k;
        if(i >= 0){
             backtrack(result, val * 10 + i , n, k, i, count+1);
        }
        
        int j = lastval + k;
        if(j <= 9 && j != i){
            backtrack(result, val * 10 + j , n, k, j, count+1);
        }
    }
}