class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows > 0) {
            generate(numRows, result);
        }
        return result;
    }
    
    private List<Integer> generate(int numRows, List<List<Integer>> result) {
        if (numRows == 1) {
            List<Integer> list = Arrays.asList(1);
            result.add(list);
            return list;
        }
        List<Integer> tmp = generate(numRows - 1, result);
        List<Integer> nextList = next(tmp);
        result.add(nextList);
        return nextList;
    }
    
    private List<Integer> next(List<Integer> previous) {
        List<Integer> result = new ArrayList<>(previous.size() + 1);
        result.add(1);
        for (int i = 1; i < previous.size(); i++) {
            int val = previous.get(i) + previous.get(i - 1);
            result.add(val);
        }
        result.add(1);
        return result;
 
    }
}