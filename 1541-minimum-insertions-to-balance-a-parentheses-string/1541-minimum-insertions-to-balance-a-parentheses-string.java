class Solution {
   public int minInsertions(String s) {
    if (s.isEmpty()) return 0;
    int openNum = 0, count = 0;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (c == '(') {
            openNum++;
        } else {
            //check if ')' is in pair
            if (i == s.length() - 1 || s.charAt(i + 1) != ')') count++;
            else i++;
            //check if missing a '(' 
            if (openNum == 0) count++;
            else openNum--;
        }
    }
    count += (2 * openNum);
    return count;
}
}