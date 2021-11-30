class Solution {
    public int numberOfSubstrings(String s) {
        int count = 0;
        Map<Character,Integer> map = new HashMap();
        int string_len = s.length();
        int right =0;
        char removed_element='z';
        for(int left =0; left<string_len; left++){
            int first_occurence_of_removed = map.getOrDefault(removed_element,-1);
            if( left <= first_occurence_of_removed ){
                count = count + string_len - right;
                removed_element = s.charAt(left);
                continue;
            }else{
                map.remove(removed_element);
            }
            while(right<string_len){
                map.put(s.charAt(right),right);
                if(map.size()==3){
                    count = count + string_len - right;
                    break;
                }
                right++;
            }
            removed_element = s.charAt(left);
            
        }
        return count;
    }
}