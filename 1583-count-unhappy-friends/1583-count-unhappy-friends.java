class Solution {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        int[][] pf = new int[n][n];
        for (int i=0;i<n;i++) {
            for (int j=0;j<n-1;j++) {
                pf[i][preferences[i][j]] = j;
            }
        }
        int c = 0;
        int n1 = pairs.length;
        Set<Integer> s = new HashSet<>();
        for (int i=0;i<n1;i++) {
            for (int j=i+1;j<n1;j++) {
                if (((pf[pairs[i][0]][pairs[j][0]] < pf[pairs[i][0]][pairs[i][1]]) && 
                     (pf[pairs[j][0]][pairs[i][0]] < pf[pairs[j][0]][pairs[j][1]])) || 
                    ((pf[pairs[i][0]][pairs[j][1]] < pf[pairs[i][0]][pairs[i][1]]) && 
                     (pf[pairs[j][1]][pairs[i][0]] < pf[pairs[j][1]][pairs[j][0]]))) {
                    s.add(pairs[i][0]);
                }
                if (((pf[pairs[i][1]][pairs[j][0]] < pf[pairs[i][1]][pairs[i][0]]) && 
                     (pf[pairs[j][0]][pairs[i][1]] < pf[pairs[j][0]][pairs[j][1]])) || 
                    ((pf[pairs[i][1]][pairs[j][1]] < pf[pairs[i][1]][pairs[i][0]]) && 
                     (pf[pairs[j][1]][pairs[i][1]] < pf[pairs[j][1]][pairs[j][0]]))) {
                    s.add(pairs[i][1]);
                }
                if (((pf[pairs[j][0]][pairs[i][0]] < pf[pairs[j][0]][pairs[j][1]]) && 
                     (pf[pairs[i][0]][pairs[j][0]] < pf[pairs[i][0]][pairs[i][1]])) || 
                    ((pf[pairs[j][0]][pairs[i][1]] < pf[pairs[j][0]][pairs[j][1]]) && 
                     (pf[pairs[i][1]][pairs[j][0]] < pf[pairs[i][1]][pairs[i][0]]))) {
                    s.add(pairs[j][0]);
                }
                if (((pf[pairs[j][1]][pairs[i][0]] < pf[pairs[j][1]][pairs[j][0]]) && 
                     (pf[pairs[i][0]][pairs[j][1]] < pf[pairs[i][0]][pairs[i][1]])) || 
                    ((pf[pairs[j][1]][pairs[i][1]] < pf[pairs[j][1]][pairs[j][0]]) && 
                     (pf[pairs[i][1]][pairs[j][1]] < pf[pairs[i][1]][pairs[i][0]]))) {
                    s.add(pairs[j][1]);                    
                }
            }
        }
        return s.size();
    }
}