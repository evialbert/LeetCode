class Solution {
    // BFS
    // compress each matrix to a string
    // for example, [[4,1,2],[5,0,3]] is represented as a String "412503"
    // then do BFS from the starting string until the target String "123450" is reached
    // if no target String is reached at the end of BFS, then return -1 since it is impossible.
    public int slidingPuzzle(int[][] board) {
        // get the size of matrix
        int m = board.length;
        int n = board[0].length;
        // 4 possible directions (neighbours) of the cell with 0 in it
        int[] direcs = new int[]{0, 1, 0, -1, 0};
        Set<String> visited = new HashSet<String>();
        Queue<String> boards = new LinkedList<String>();
        StringBuilder sb = new StringBuilder();
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                sb.append(board[y][x]);
            }
        }
        String start = sb.toString();
        visited.add(start);
        boards.add(start);
        int res = 0;
        while (!boards.isEmpty()) {
            int size = boards.size();
            while (size > 0) {
                String curr = boards.poll();
                if (curr.equals("123450")) return res;
                int index = curr.indexOf('0');
                int y = index / n;
                int x = index % n;
                for (int i = 0; i < direcs.length - 1; i++) {
                    int r = y + direcs[i];
                    int c = x + direcs[i + 1];                        
                    if (r < 0 || r >= m || c < 0 || c >= n) continue;
                    int neighbourIndex = r * n + c;
                    String swapped = swap(curr, index, neighbourIndex);
                    if (!visited.contains(swapped)) {
                        boards.add(swapped);
                        visited.add(swapped);
                    }
                }
                size--;
            }
            res++;
        }
        return -1;
    }
    private String swap(String curr, int index, int neighbourIndex) {
        char[] temp = curr.toCharArray();
        char ch = temp[index];
        temp[index] = temp[neighbourIndex];
        temp[neighbourIndex] = ch;
        String swapped = String.valueOf(temp);
        return swapped;
    }
}