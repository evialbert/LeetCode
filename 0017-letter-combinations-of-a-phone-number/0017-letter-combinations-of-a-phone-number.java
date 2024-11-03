class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> s = new ArrayList<>();
        
        if(digits == null || digits.length() == 0)
            return s;
        
        int len = digits.length();
        int arr[] = new int[len];
        for(int i =0 ;i< len ; i++){
            arr[i]  = digits.charAt(i)-'0';
        }
        
        String letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        Queue<String> que = new LinkedList<>();
        que.offer(""); //better then queue.add() as it does not throw run time exception
        
        for(int i =0 ; i< len; i++){
            String word = letters[arr[i]-2];
            int size = que.size();
            for (int j = 0; j < size; j++) {
                String temp = que.poll();
                for (char ch : word.toCharArray()) {
                    que.offer(temp + ch);
                }
            }
        }
        return new ArrayList<>(que);
    }
}