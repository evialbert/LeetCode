class Solution {
    public String removeDuplicateLetters(String s) {
        Map<Character, Integer> map = new HashMap<>();
        
        for(int i=0;i<s.length();i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i),0)+1);
        }
        
        Set<Character> used = new HashSet<>();
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<s.length();i++){
            
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i),0)-1);
            
            if(used.contains(s.charAt(i))){
                continue;    
            }
                        
            if(sb.length() == 0){
                 sb.append(s.charAt(i));
                 used.add(s.charAt(i));
            }
            else{
                char currentLetter = s.charAt(i);
                while(sb.length() > 0 && (sb.charAt(sb.length()-1) > currentLetter)){
                    char prevLetter = sb.charAt(sb.length()-1);
                    if(map.get(prevLetter) >= 1){
                        sb.deleteCharAt(sb.length()-1);
                        used.remove(prevLetter);
                    }else{
                        break;
                    }
                }
                sb.append(currentLetter);
                used.add(currentLetter);
            }
            
        }

        return sb.toString();
    }
}