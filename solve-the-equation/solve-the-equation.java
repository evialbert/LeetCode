class Solution {
    public String solveEquation(String equation) {
        String split[] = equation.split("=");
        int left[] = solve(split[0]);
        int right[] = solve(split[1]);

        int x = left[0] - right[0]; // compute diff of x         left - right
        int y = right[1] - left[1]; // compute diff of constant  right - left

        if (x == 0) {
            if (y == 0)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + (y / x);
    }

    private int[] solve(String s) {
        int res[] = new int[2];
        char sign = '+';
        int num = 0;
        boolean isNum = false;
        s = s + "+"; // in case if equation is ending with constant eg:2x+5
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                num = num * 10 + (ch - '0'); // compute continuous digits
                isNum = true;
            } else if (ch == 'x') {
                int n = isNum ? num : 1; // check if x  has continuous digits eg:23x
                res[0] += sign == '-' ? -n : n;
                isNum = false;//reset num & sign for next run
                num = 0; 
            } else if (ch == '+' || ch == '-') {
                res[1] += sign == '-' ? -1 * num : num;  // when you encounter +/-, add the constant to result. This will skip adding coefficient of x as we already reset num to 0
                isNum = false;
                num = 0; //reset num & sign for next run
                sign = ch; 
            }
        }
        return res;
    }
}