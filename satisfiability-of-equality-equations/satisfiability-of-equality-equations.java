class Solution {
    public boolean equationsPossible(String[] equations) {
        int[][] graph = new int[26][26];
        for(String equation:equations){
            if(equation.charAt(1)=='='){
                graph[equation.charAt(0)-'a'][equation.charAt(3)-'a']=1;
                graph[equation.charAt(3)-'a'][equation.charAt(0)-'a']=1;
            }
        }
        boolean[] visited = new boolean[26];
        for(String equation:equations){
            if(equation.charAt(1)=='!' && solve(equation.charAt(0)-'a',equation.charAt(3)-'a',graph,visited)){
                return false;
            }
        }
        return true;
    }
    public boolean solve(int start,int end,int[][] graph,boolean[] visited){
        if(start==end)return true;
        if(visited[start])return false;
        visited[start]=true;
        for(int i=0;i<26;i++){
            if(graph[start][i]==1 && solve(i,end,graph,visited)){
                return true;
            }
        }
        visited[start]=false;
        return false;
    }
}