class Solution {
    public int findJudge(int N, int[][] trust) {
        if(N < 2){
            return N;
        }
        
        HashSet<Integer> [] trustSets = new HashSet[N+1];
        for(int i = 1; i<=N; i++){
            trustSets[i] = new HashSet<>();
        }
        
        for(int [] t : trust){
            trustSets[t[0]].add(t[1]);
        }
        
        int c = -1;
        for(int i = 1; i<=N; i++){
            if(trustSets[i].isEmpty()){
                c = i;
            }
        }
        
        for(int i = 1; i<=N; i++){
            if(i != c && !trustSets[i].contains(c)){
                return -1;
            }
        }
        
        return c;
    }
}