class Solution {   
    
    static int[][][][] memo = new int[100][101][100][26];
    
    public int getLengthOfOptimalCompression(String s, int k) {
        int n = s.length();
        for(int i = 0; i < n; i++) 
            for(int j = 0; j <= k; j++) 
                for(int z = 0; z < n; z++) 
                    for(int l = 0; l < 26; l++)
                        memo[i][j][z][l]=-1;
        return fun(s, k, 0, '1', 0, memo);
    }
    
    int fun(String s, int k, int x, char ch, int count, int[][][][] memo) {
        if(x==s.length()) {
            return 0;
        }
        if(ch!='1')
        if (memo[x][k][count][ch-'a'] != -1) return memo[x][k][count][ch-'a'];
        //System.out.println(ch-'a');
        int min = 1000;
        if(k>0)
            min=Math.min(min, fun(s, k-1, x+1, ch, count, memo));
        char c = s.charAt(x);
        if(ch == c) {
            int temp = 0;
            if(count==1 || count==9 || count==99) temp=1;
            min=Math.min(min, fun(s, k, x+1, c, count+1, memo)+temp);
        } else min=Math.min(min, fun(s, k, x+1, c, 1, memo)+1);
        if(ch!='1')
        memo[x][k][count][ch-'a'] = min;
        return min;
    }
    
}