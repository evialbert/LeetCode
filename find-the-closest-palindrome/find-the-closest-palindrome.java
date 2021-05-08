class Solution {
  public String nearestPalindromic(String n) {
        if(n.equals("1")) return "0";
        long original = Long.parseLong(n);
        StringBuilder sb = new StringBuilder();
        String left = n.substring(0,(n.length()-1)/2+1);
        long leftLong = Long.parseLong(left);
        
        sb.append(""+leftLong);
        String leftFlip = sb.reverse().toString();
        
        sb.setLength(0);
        sb.append(""+(leftLong+1));
        String leftLongPlusOne = sb.toString();
        if(leftLongPlusOne.length()>left.length()){
            leftLongPlusOne = leftLongPlusOne.substring(0,leftLongPlusOne.length()-1);
        }
        String leftPlusOneFlip = n.length()%2!=0 ? sb.reverse().substring(1,sb.length()) : sb.reverse().toString();
        
        
        sb.setLength(0);
        sb.append(""+(leftLong-1));
        String leftLongMinusOne = sb.toString();
        leftLongMinusOne = leftLongMinusOne.equals("0") ? "9" : leftLongMinusOne;
        if(leftLongMinusOne.equals("0")){
            leftLongMinusOne = "9";
        }
        else if(leftLongMinusOne.length()<left.length()){
            leftLongMinusOne = leftLongMinusOne+"9";
        }
        String leftMinusOneFlip = n.length()%2!=0 || left.equals("1") ? sb.reverse().substring(1,sb.length()) : sb.reverse().toString();
        
        
        long candidate1 = Long.parseLong(left + (n.length()%2==0 ? leftFlip : leftFlip.substring(1,leftFlip.length())));
        long candidate2 = Long.parseLong(leftLongPlusOne + leftPlusOneFlip);
        long candidate3 = Long.parseLong(leftLongMinusOne + leftMinusOneFlip);
        
        long min = candidate1 == original ? Math.min(Math.abs(candidate2-original),Math.abs(candidate3-original)) : Math.min(Math.abs(candidate1-original),Math.min(Math.abs(candidate2-original),Math.abs(candidate3-original)));
        
        if(min == Math.abs(candidate3-original)){
            return candidate3+"";
        }
        else if(min == Math.abs(candidate1-original)){
            return candidate1+"";
        }
        else{
            return candidate2+"";
        }
    }
}