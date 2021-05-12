class Solution {
    public String fractionAddition(String expression) {
		String tokens[] = expression.split("(?=[-+])");
		int res[] = new int[] {0,1};
		int num1=0,num2=0;	
		for (String token : tokens) {
			if (token.startsWith("-") || token.startsWith("+") || token.startsWith("")) {
				num1 = Integer.parseInt(token.substring(0, token.indexOf("/")));
				num2 = Integer.parseInt(token.substring(token.indexOf("/") + 1, token.length()));
				res[0] = num2 * res[0] + num1 * res[1];
				res[1] = res[1] * num2;
			}
		}
		if(res[0]==0) {
			return "0/1";
		}else {
			return asFraction(res[0],res[1]);
		}
	}
	public static long gcd(long a, long b) {
	    return b == 0 ? a : gcd(b, a % b);
	}

	public static String asFraction(long a, long b) {
	    long gcd = gcd(a, b);
	    if(gcd<0) {
	    	return -1*(a / gcd) + "/" + (b / gcd)*-1;
	    }else 
	    	return (a / gcd) + "/" + (b / gcd);
	}
}