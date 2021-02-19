class Solution {
     public String addBinary(String a, String b) {
        int i = a.length() - 1, j = b.length() - 1;
        int top = 0, res = 0;
        int[] stack = new int[i > j ? i + 2 : j + 2];
        int len = i > j ? i : j;
        while (len-- >= 0) {
            res = res + (i >= 0 ? a.charAt(i) - 48 : 0) + (j >= 0 ? b.charAt(j) - 48 : 0);
            stack[top++] = ( res % 2);
            res /= 2;
            i--;
            j--;
        }
        if (res > 0) 
            stack[top++] = res;
        char[] result = new char[top];
        i = 0;
        while (top > 0) 
            result[i++] = (char)(stack[--top] + 48) ;
        return new String(result);
    }

}