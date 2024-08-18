class Solution {
    TreeMap<Integer, Integer> treeMap = new TreeMap<>(); // map[group_start] = len
    Map<Integer, Integer> lengthCnt = new HashMap<>(); // map[group_len] = counter

    public List<Integer> numberOfAlternatingGroups(int[] colors, int[][] queries) {
        int n = colors.length;

        // getting and indexing all alternating group starts
        int start = 1;
        while (start < n && colors[start] != colors[start - 1]) {
            start++; // looking for a good first 'cut'
        }
        start = start % n;
        int lastEnd = start;
        for (int i = start; i < n;) {
            int end = i + 1;
            while (end - i < n && colors[end % n] != colors[(end + n - 1) % n]) {
                end++; // max possible end-start len is N
            }
            addGroup(i, end - i);
            i += end - i;
            lastEnd = end % n;
        }
        if (lastEnd != start) { // the last group spans over the end of the array
            addGroup(lastEnd, (start + n - lastEnd) % n);
        }

        List<Integer> result = new ArrayList<>();
        for (int[] q : queries) {
            if (q[0] == 1) { // count query
                int size = q[1];
                int cnt = 0;
                for (int len : lengthCnt.keySet()) {
                    int subGroups = len == n && isSingleCycle(treeMap.keySet().iterator().next(), len, colors) ?
                        n /* == len -> any positions is a good group start */ :
                        Math.max(1 + len - size, 0);
                    cnt += subGroups * lengthCnt.get(len);
                }
                result.add(cnt);
            } else { // update query
                int updateIdx = q[1];
                int newValue = q[2];
                if (newValue == colors[updateIdx]) {
                    continue; // nothing changes
                }

                updateValue(colors, updateIdx, newValue);
            }
        }
        return result;
    }

    private void updateValue(int[] colors, int updateIdx, int newValue) {
        int n = colors.length;

        // cases: group split, groups merge
        int groupStart = Objects.requireNonNullElse(treeMap.floorKey(updateIdx), treeMap.floorKey(updateIdx + n));
        int groupLen = removeGroup(groupStart);
        int groupEnd = (groupStart + groupLen) % n;

        // 1) let's detach head & tail groups if any, so updateIdx becomes a 1-len group
        int headStart = groupStart;
        int headLen = (updateIdx + n - headStart) % n; // %n is safe here max len is n-1 here
        int tailStart = (updateIdx + 1) % n;
        int tailLen = (groupEnd + n - tailStart) % n; // ^ ... b/c updateLen == 1
        if (isSingleCycle(groupStart, groupLen, colors)) {
            addGroup(tailStart, n - 1);
        } else {
            if (headLen > 0) {
                addGroup(headStart, headLen);
            }
            if (tailLen > 0) {
                addGroup(tailStart, tailLen);
            }
        }

        // 2) now we have a single missing cell - updatedCell, let's merge it with
        // neighbours if possible
        int newStart = updateIdx;
        int newLen = 1;
        int prevStart = Objects.requireNonNullElse(treeMap.floorKey(newStart), treeMap.floorKey(newStart + n));
        int nextStart = Objects.requireNonNullElse(treeMap.ceilingKey(newStart), treeMap.ceilingKey(newStart - n));
        colors[newStart] = newValue;
        boolean nextJoined = false;
        if ((newStart + 1) % n == nextStart && colors[newStart] != colors[nextStart]) {
            // merging with the next group
            newLen += removeGroup(nextStart);
            nextJoined = true;
        }
        if ((prevStart != nextStart || !nextJoined) && colors[(newStart + n - 1) % n] != colors[newStart]) {
            // merging with the previous group
            newLen += removeGroup(prevStart);
            newStart = prevStart;
        }
        addGroup(newStart, newLen);
    }

    private void addGroup(int start, int len) {
        treeMap.put(start, len);
        lengthCnt.compute(len, (k, v) -> (v != null ? v : 0) + 1);
    }

    private int removeGroup(int start) {
        int len = treeMap.remove(start);
        lengthCnt.compute(len, (k, v) -> v == 1 ? null : v - 1);
        return len;
    }

    // checking if we have a single cycle of length N without any break point
    private boolean isSingleCycle(int start, int len, int[] colors) {
        int n = colors.length;
        if (len == n) {
            if (colors[start] != colors[(start + n - 1) % n]) {
                return true;
            }
        }
        return false;
    }
}