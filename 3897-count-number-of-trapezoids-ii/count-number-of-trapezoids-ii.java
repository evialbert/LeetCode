class Solution {
    public int gcd(int a, int b) {
        int temp;
        while ((temp = a % b) != 0) {
            a = b;
            b = temp;
        }
        return b;
    }

    public int countTrapezoids(int[][] points) {
        int length = points.length;
        Map<String, List<int[]>> midMap = new HashMap<>();
        Map<String, Map<Integer, Integer>> slopeMap = new HashMap<>();
        for (int i = 0; i < length; i++) {
            int[] first = points[i];
            for (int j = i + 1; j < length; j++) {
                int[] second = points[j];
                int midX = first[0] + second[0];
                int midY = first[1] + second[1];
                String key = midX + "," + midY;
                midMap.putIfAbsent(key, new ArrayList<>());
                midMap.get(key).add(new int[] { i, j });
                int distX = second[0] - first[0];
                int distY = second[1] - first[1];
                if (distX == 0) {
                    key = "vertical";
                } else if (distY == 0) {
                    key = "horizontal";
                } else {
                    int x = Math.abs(distX);
                    int y = Math.abs(distY);
                    int gcd = gcd(x, y);
                    key = x / gcd + (distX * distY > 0 ? "+" : "-") + y / gcd;
                }
                slopeMap.putIfAbsent(key, new HashMap<>());
                Map<Integer, Integer> innerMap = slopeMap.get(key);
                Integer val = innerMap.get(i);
                if (val == null) {
                    innerMap.put(i, i);
                    innerMap.put(j, i);
                } else {
                    innerMap.put(j, val);
                }
            }
        }
        int res = 0;
        for (Map<Integer, Integer> map : slopeMap.values()) {
            int preSum = 0;
            Map<Integer, Integer> innerMap = new HashMap<>();
            for (int val : map.values()) {
                innerMap.merge(val, 1, Integer::sum);
            }
            for (int val : innerMap.values()) {
                int cur = (val - 1) * val / 2;
                res += preSum * cur;
                preSum += cur;
            }
        }
        for (List<int[]> list : midMap.values()) {
            if (list.size() != 1) {
                Map<String, Integer> innerMap = new HashMap<>();
                for (int[] arr : list) {
                    int[] first = points[arr[0]];
                    int[] second = points[arr[1]];
                    int distX = second[0] - first[0];
                    int distY = second[1] - first[1];
                    String key;
                    if (distX == 0) {
                        key = "vertical";
                    } else if (distY == 0) {
                        key = "horizontal";
                    } else {
                        int x = Math.abs(distX);
                        int y = Math.abs(distY);
                        int gcd = gcd(x, y);
                        key = x / gcd + (distX * distY > 0 ? "+" : "-") + y / gcd;
                    }
                    innerMap.merge(key, 1, Integer::sum);
                }
                int preSum = 0;
                for (int val : innerMap.values()) {
                    res -= preSum * val;
                    preSum += val;
                }
            }
        }
        return res;
    }
}