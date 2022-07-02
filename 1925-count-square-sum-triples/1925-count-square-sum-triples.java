class Solution {
    public int countTriples(int n) {
        int answer = 0;
        Set<Integer> squared = new HashSet<>();
        for(int i=1;i<=n;i++) {
            squared.add(i * i);
        }
        for(int a: squared) {
            for(int b: squared) {
                if(squared.contains(a + b)) {
                    answer++;
                }
            }
        }
        return answer;
    }
}