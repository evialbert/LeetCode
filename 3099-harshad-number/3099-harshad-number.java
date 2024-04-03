class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        String s = Integer.toString(x);
        int sum = 0;
        for(int i=0; i<s.length(); i++){
            sum += s.charAt(i)-'0';
        }
        if(x % sum == 0){
            return sum;
        }else {
            return -1;
        }
    }
}