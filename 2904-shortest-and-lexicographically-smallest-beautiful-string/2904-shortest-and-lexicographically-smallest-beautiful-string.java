class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        String res = "";
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                queue.add(i);
            }
            if (queue.size() > k) queue.poll();
            if (queue.size() == k) {
                String sub = s.substring(queue.peek(), i + 1);
                if (res.isEmpty()) {
                    res = sub;
                } else {
                    if (res.length() > sub.length()) {
                        res = sub;
                    } else if (res.length() == sub.length()){
                        res = res.compareTo(sub) > 0 ? sub : res;
                    }
                }
            }
        }
        return res;
    }
}