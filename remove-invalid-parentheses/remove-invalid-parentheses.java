public class Solution {
public List<String> removeInvalidParentheses(String s) {
    List<String> res = new ArrayList<>();
    if (s == null || s.length() == 0) {
        res.add("");
        return res;
    }
    Set<String> hs = new HashSet<>();
    int[] maxLen = new int[1];
    removeParenthesesHelper(s, 0, 0, 0, "", maxLen, hs);
    for (String cur : hs) {
        res.add(cur);
    }
    return res;
}

private void removeParenthesesHelper(String s, int pos, int leftCount, int rightCount, String str, int[] maxLen, Set<String> res) {
    if (leftCount < rightCount) return;
    if (pos >= s.length()){
        if (leftCount != rightCount) return;
        if (res.size() == 0 || maxLen[0] == str.length()){
            res.add(str);
            maxLen[0] = str.length();
        } else if (maxLen[0] < str.length()){
            res = new HashSet<>();
            res.add(str);
            maxLen[0] = str.length();
        } 
        return;
    }
    if (s.charAt(pos) == '('){
        removeParenthesesHelper(s, pos + 1, leftCount + 1, rightCount, str + "(", maxLen, res);
        removeParenthesesHelper(s, pos + 1, leftCount, rightCount, str, maxLen, res);
    } else if (s.charAt(pos) == ')'){
        removeParenthesesHelper(s, pos + 1, leftCount, rightCount + 1, str + ")", maxLen, res);
        removeParenthesesHelper(s, pos + 1, leftCount, rightCount, str, maxLen, res);
    } else {
        removeParenthesesHelper(s, pos + 1, leftCount, rightCount, str + s.charAt(pos), maxLen, res);
    }
}
}