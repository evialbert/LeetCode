class Solution {
    public int minOperations(String s) {
        if (s.length() == 2) {
            if (s.charAt(0) > s.charAt(1)) {
                return -1;
            } else {
                return 0;
            }
        }
        if (s.length() == 1) {
            return 0;
        }
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        int index = -1;
        String sorted = new String(arr);
        for (int i = 0; i < s.length(); i++) {
            if (sorted.charAt(i) == s.charAt(i)) {
                index = i;
            } else {
                break;
            }
        }
        String answer = s + "";
        int res = Integer.MAX_VALUE;
        int count = 0;
        if (index == -1) {
            while (true) {
                answer = left(answer);
                count++;
                if (answer.equals(sorted)) {
                    res = Math.min(res, count);
                    break;
                }
                answer = right(answer);
                count++;
                if (answer.equals(sorted)) {
                    res = Math.min(res, count);
                    break;
                }
            }
            answer = s + "";
            count = 0;
            while (true) {
                answer = right(answer);
                count++;
                if (answer.equals(sorted)) {
                    res = Math.min(res, count);
                    break;
                }
                answer = left(answer);
                count++;
                if (answer.equals(sorted)) {
                    res = Math.min(res, count);
                    break;
                }
            }
        } else {
            if (index == s.length() - 1) {
                return 0;
            }
            return 1;
        }
      return res;
    }

    String right(String s){
    String part = s.substring(1);
    char[] arr = part.toCharArray();
    Arrays.sort(arr);
    return s.charAt(0) + new String(arr);
}

String left(String s){
    String part = s.substring(0, s.length()-1);
    char[] arr = part.toCharArray();
    Arrays.sort(arr);
    return new String(arr) + s.charAt(s.length()-1);
}
}