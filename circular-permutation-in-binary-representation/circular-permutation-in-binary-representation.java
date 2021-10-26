class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        var list = permutation(n);
        int index = list.indexOf(start);
        
        List<Integer> answer = new ArrayList<>();
        answer.addAll(list.subList(index, list.size()));
        answer.addAll(list.subList(0, index));
        return answer;
    }
    
    private List<Integer> permutation(int n) {
        List<Integer> list = new ArrayList<>();
        
        if (n == 1) {
            list.add(0);
            list.add(1);
            return list;
        }
        
        var left = permutation(n - 1);
        var right = new ArrayList<>(left);
        
        Collections.reverse(right);
        for (int i = 0; i < right.size(); i++) {
            right.set(i, right.get(i) | (1 << (n - 1)));
        }
        
        list.addAll(left);
        list.addAll(right);
        return list;
    }
}