class Solution {
      public List<String> stringSequence(String target) {
        StringBuilder sb = new StringBuilder();
        List<String> resul = new ArrayList<>();
        //iterate through the whole target string
        for (char c : target.toCharArray()) {
            //first keypad
            sb.append('a');
            resul.add(sb.toString());
            //second keypad
            while (sb.charAt(sb.length() - 1) != c) {
                char last = sb.charAt(sb.length() - 1);
                //update and check for edge case
                char next = (char) (last == 'z' ? 'a' : last + 1);
                //replace at last character in sb
                sb.setCharAt(sb.length() - 1, next);
                resul.add(sb.toString());
            }
        }
        return resul;
    }
}