class Solution {
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        int[] rowOrder = getTopologicalOrder(k, rowConditions);
        int[] colOrder = getTopologicalOrder(k, colConditions);

        if (rowOrder == null || colOrder == null) {
            return new int[0][0];
        }

        int[][] matrix = new int[k][k];
        int[] rowIndex = new int[k + 1];
        int[] colIndex = new int[k + 1];

        for (int i = 0; i < k; i++) {
            rowIndex[rowOrder[i]] = i;
            colIndex[colOrder[i]] = i;
        }

        for (int num = 1; num <= k; num++) {
            matrix[rowIndex[num]][colIndex[num]] = num;
        }

        return matrix;
    }

    private int[] getTopologicalOrder(int k, int[][] conditions) {
        List<Integer>[] graph = new List[k + 1];
        int[] inDegree = new int[k + 1];

        for (int i = 1; i <= k; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] condition : conditions) {
            graph[condition[0]].add(condition[1]);
            inDegree[condition[1]]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }

        int[] order = new int[k];
        int index = 0;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            order[index++] = current;

            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }

        return index == k ? order : null;
    }
}