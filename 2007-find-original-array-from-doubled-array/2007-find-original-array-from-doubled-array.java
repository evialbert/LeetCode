class Solution {
    public int[] findOriginalArray(int[] changed) {
        if (changed.length %2 != 0) {
            return new int[0];
        }
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : changed) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        Arrays.sort(changed);

        List<Integer> orig = new ArrayList<>();
        for (int i = 0; i < changed.length; i++) {
            int num = changed[i];
            int dob = 2 * num;
            if (map.containsKey(num) && map.containsKey(dob)) {
                orig.add(num);
                int numVal = map.get(num) - 1;
                if (numVal > 0) {
                    map.put(num, numVal);
                } else {
                    map.remove(num);
                }
                if (map.containsKey(dob)) {
                    int dobVal = map.get(dob) - 1;
                    if (dobVal > 0) {
                        map.put(dob, dobVal);
                    } else {
                        map.remove(dob);
                    }
                } else {
                    return new int[0];
                }
            }
        }
        if (orig.size() == changed.length / 2) {
            int[] result = new int[orig.size()];
            for (int i = 0; i < orig.size(); i++) {
                result[i] = orig.get(i);
            }
            return result;
        }
        return new int[0];
    }
}