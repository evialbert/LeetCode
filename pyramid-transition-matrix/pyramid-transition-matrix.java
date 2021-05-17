class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, List<Character>> validTriangles = new HashMap<>();
        for (String str : allowed) {
            validTriangles.computeIfAbsent(str.substring(0, 2), l -> new ArrayList<>()).add(str.charAt(2));
        }
        return helper(bottom, validTriangles);
    }
    
    private boolean helper(String bottom, Map<String, List<Character>> validTriangles) {
        if (bottom.length() == 1) {
            return true;
        }
        int n = bottom.length();
        List<String> comb = new ArrayList<>();
        List<List<Character>> possible = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            if (!validTriangles.containsKey(bottom.charAt(i) + "" + bottom.charAt(i + 1))) {
                return false;
            }
            possible.add(validTriangles.get(bottom.charAt(i) + "" + bottom.charAt(i + 1)));
        }
        dfs(possible, 0, "", comb);
        for (String next : comb) {
            if (helper(next, validTriangles)) {
                return true;
            }
        }
        return false;
    }
    
    private void dfs(List<List<Character>> possible, int index, String cur, List<String> comb) {
        if (index == possible.size()) {
            comb.add(cur);
            return;
        }
        for (char ch : possible.get(index)) {
            dfs(possible, index + 1, cur + ch, comb);
        }
    }
}