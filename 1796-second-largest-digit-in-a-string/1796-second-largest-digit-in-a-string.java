class Solution {
    public int secondHighest(String s) {
        ArrayList<Character> num = new ArrayList<>();
        for(int i=0; i<s.length();i++){
            if(Character.isDigit(s.charAt(i)))
                {
                if(!num.contains(s.charAt(i)))
                     num.add(s.charAt(i));
                
                  
        }
        }
        
        Collections.sort(num);
        if(num.size()==1 || num.size()==0)
            return -1;
        
        return Character.getNumericValue(num.get(num.size()-2));
        
    }
}