class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> ans = new ArrayList<>();

        for (String q : queries) {
            for (String d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.length(); i++) {
                    if (q.charAt(i) != d.charAt(i)) {
                        diff++;
                    }

                    if (diff > 2) break;
                }

                if (diff <= 2) {
                    ans.add(q);
                    break;
                }
            }
        }

        return ans;
    }
}