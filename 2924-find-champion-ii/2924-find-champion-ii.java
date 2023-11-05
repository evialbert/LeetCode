class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] countSuperiors = new int[n];
        
        for (int[] edge : edges) {
            countSuperiors[edge[1]]++;
        }

        int winner = -1;

        for (int i = 0; i < n; i++) {
            if (countSuperiors[i] == 0) {
                if (winner != -1) return -1;
                winner = i;
            }
        }

        return winner;
    }
}

//Time complexity: O(n)
//Space complexity: O(n)