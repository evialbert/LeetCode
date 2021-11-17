class Solution {
    public List<String> printVertically(String s) {
        
        int maxlength = 0;
		//convert to string array
        String[] s_array = s.split(" "); 
		//find out maxlength string in string array
        for(String str : s_array){
            if(str.length() > maxlength){
                maxlength = str.length();
            }
        }
        int index = 0;
        List<String> list = new ArrayList<>();
		//loop till maxlength 
        for(int i = 0; i < maxlength; i++){
            StringBuilder sb = new StringBuilder();
            for(String str : s_array){
                if(index < str.length()){
                    sb.append(str.charAt(index));
                }else{
                    sb.append(" ");
                }
            }
			// this will remove trailing spaces from string
            list.add(sb.toString().stripTrailing());
            index++;
        }
        return list;
    }
}