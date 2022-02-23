class Solution {
    public String thousandSeparator(int n) {
        if(n < 1000) return Integer.toString(n);
        StringBuilder sb = new StringBuilder();
        int count = 0;
        while(n > 0){
            sb.append(n % 10);
            count++;
            n /= 10;
            if(count % 3 == 0 && n > 0){  //n > 0 is checked so that if there are 6 digits then it won't add '.' after 6 th digit as it will be end no. (eg, to avoid this->  .123.456)
                sb.append(".");
            }
        }
        return sb.reverse().toString();
    }
}