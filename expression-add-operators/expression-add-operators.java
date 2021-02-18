public class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> result = new LinkedList<String>();
        process("", 0, 0, result, num, target);
        return result;
    }
    private void process(String curr, long sum, long addToSum, List<String> result, String num, int target) {
        if (num.length() == 0 && target == sum) {
            result.add(curr);
            return;
        }
        for (int i = 1; i <= num.length(); i ++) {
            String first = num.substring(0, i);
            String second = num.substring(i);
            if (first.charAt(0) == '0' && first.length() > 1) {
                return;
            }
            long firstLong = Long.parseLong(first);
            if (curr.equals("")) {
                process(first, firstLong, firstLong, result, second, target);
            }
            else {
                process(curr + "+" + first, sum + firstLong, firstLong, result, second, target);
                process(curr + "-" + first, sum - firstLong, -firstLong, result, second, target);
                process(curr + "*" + first, (sum - addToSum) + addToSum * firstLong, addToSum * firstLong, result, second, target);
            }
        }
    }
}