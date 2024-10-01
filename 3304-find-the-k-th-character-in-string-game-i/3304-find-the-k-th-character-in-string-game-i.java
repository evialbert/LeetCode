class Solution {
    public char kthCharacter(int k) {
        StringBuilder stb = new StringBuilder("ab");

        String str = finder(stb, k);
        return str.charAt(k - 1);

    }

    public String finder(StringBuilder stb, int k) {
        if (stb.length() > k) {
            return stb.toString();
        }

        int size = stb.length();
        String sub = stb.substring(size / 2, size);
        stb.append(sub);
     
          size=sub.length();
       
        char ch;
        for (int i = 0; i < size; i++) {
            if (sub.charAt(i) == 'z') {
                ch = 'a';
            } else {
                ch = (char) (sub.charAt(i) + 1);
            }

            stb.append(ch);

        }
        finder(stb, k);
        return stb.toString();

    }
}