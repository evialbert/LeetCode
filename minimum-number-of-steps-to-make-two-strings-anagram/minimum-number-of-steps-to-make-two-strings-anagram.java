class Solution {
    public int minSteps(String s, String t) {
        HashMap<Character,Integer> hm=new HashMap<>();
        for(int i =0;i<s.length();i++){
            char ch =s.charAt(i);
            if(hm.containsKey(ch)){
                int freq=hm.get(ch);
                freq++;
                hm.put(ch,freq);
            }
            else{
                hm.put(ch,1);
            }
        }
        
        int count=0;
        
        for(int i =0;i<t.length();i++){
            char ch =t.charAt(i);
            if(hm.containsKey(ch)){
                int freq=hm.get(ch);
                freq--;
                hm.put(ch,freq);
            }
            
        }
        
        for(int i =0;i<s.length();i++){
            char ch =s.charAt(i);
            if(hm.containsKey(ch)){
                int freq=hm.get(ch);
               
               if(freq>0){
                   count+=freq; 
                    freq=0;
                }
                hm.put(ch,freq);
            }
            
        }
        return count;
        
    }
}