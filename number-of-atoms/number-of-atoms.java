class Solution {
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = new HashMap<>();
        int count = 0;
        Stack<Integer> cStack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        int prod = 1;
        for (int i=formula.length()-1; i>=0; --i) {
            char c = formula.charAt(i);
            if (Character.isDigit(c)) {
                count = count + prod * (c - '0');
                prod *= 10;
            } else if (c == ')') {
                count = (count == 0) ? 1 : count;
                cStack.push(count * (cStack.isEmpty() ? 1 : cStack.peek())); // !!!
                count = 0;
                prod = 1;
            } else if (c == '(') {
                cStack.pop();
                count = 0;
            } else if (Character.isUpperCase(c)) {
                sb.append(c);
                String key = sb.reverse().toString();
                count = (count == 0) ? 1 : count;
                count = ((cStack.isEmpty()) ? 1 : cStack.peek()) * count;
                map.put(key, map.getOrDefault(key, 0) + count);
                sb = new StringBuilder();
                count = 0;
                prod = 1;
            } else {
                sb.append(c);
            }
        }
        ArrayList<String> keys = new ArrayList(map.keySet());
        Collections.sort(keys);
        StringBuilder ans = new StringBuilder();
        for (String key : keys) {
            ans.append(key);
            if (map.get(key) > 1) {
                ans.append(map.get(key));
            }
        }
        return ans.toString();
    }
}