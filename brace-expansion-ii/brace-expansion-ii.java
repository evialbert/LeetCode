class Solution {
    public List<String> braceExpansionII(String expression) {
        if (expression == null || expression.length() == 0) return new ArrayList<>();
        List<List<String>> group = new ArrayList<>();
        Set<String> res = new TreeSet<>();
        int level = 0, start = -1;
        for (int i = 0; i < expression.length(); i++) {
            char cur = expression.charAt(i);
            if (cur == '{') {
                if (level == 0) start = i + 1; //because we use recursive so we just need to mark the first level everytime
                level++;
            } else if (cur == '}') {
                level--;
                if (level == 0) group.add(braceExpansionII(expression.substring(start, i))); //find the end and do recursive in what in the brace
            } else if (cur == ',' && level  == 0) {
                res.addAll(combine(group)); //inside the braces, combine the groups{a,b}, get a and b 
                group.clear();
            } else if (level == 0) {
                group.add(Arrays.asList(String.valueOf(cur))); //normal letter, just add to the group eg. "{a, b}c{d, e}"
            }
        }
        res.addAll(combine(group));//combine all the groups, eg "{a,b}{c,{d,e}}" there should be 2 
        return new ArrayList<>(res);
    }
    
    private List<String> combine(List<List<String>> group) {
        List<String> res = new ArrayList<>();
        res.add("");
        for (List<String> g : group) {
            List<String> temp = new ArrayList<>();
            for (String p : res) {
                for (String s : g) {
                    temp.add(p + s);
                }
            }
            res = temp;
        }
        return res;
    }
}
