class Solution {
  public long minimumSteps(String s) {
    var i = 0;
    var res = 0L;

    for (var j = 0; j < s.length(); j++) {
      if (s.charAt(j) == '0') {
        res += j - i;
        i++;
      }
    }
    return res;
  }
}