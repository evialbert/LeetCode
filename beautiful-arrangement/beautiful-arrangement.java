class Solution {
    int count;
    public void helper(int ci,int n,boolean[] visited){
        if(ci>n){
            count++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(visited[i] != true && (i%ci == 0 || ci%i == 0)){
                visited[i] = true;
                helper(ci+1,n,visited);
                visited[i] = false;
            }
        }
    }
    public int countArrangement(int n) {
        count = 0;
        boolean visited[] = new boolean[n+1];
        helper(1,n,visited);
        return count;
    }
}