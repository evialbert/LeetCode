class Solution {
   public String capitalizeTitle(String title) {
    StringBuilder sb = new StringBuilder();
	
    for(String a:  title.split(" ")){
        if(a.length() <= 2){
            sb.append(a.toLowerCase());
        }
        else
        {
            sb.append(Character.toUpperCase(a.charAt(0)));
            sb.append(a.substring(1, a.length()).toLowerCase());
        }
        sb.append(" ");
    }
    sb.deleteCharAt(sb.length()-1);
	return sb.toString();
}
}