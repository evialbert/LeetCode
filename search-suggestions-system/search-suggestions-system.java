class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        int n = searchWord.length();
        Arrays.sort(products);
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) res.add(new ArrayList<String>());
        for (String str : products) {
            for (int i = 0; i < n; i++) {
                if (i < str.length() && str.charAt(i) == searchWord.charAt(i)) {
                    if (res.get(i).size() < 3) res.get(i).add(str);
                } else break;
            }
        }
        return res;
    }
}