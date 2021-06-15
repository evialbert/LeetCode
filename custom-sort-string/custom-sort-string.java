class Solution {
    public String customSortString(String order, String str) {
        if(str.length()==0) return "";
        
        HashMap<Character,Integer> map=new HashMap<>();
        StringBuilder ans=new StringBuilder();
        
        for(int i=0;i<str.length();i++){
            char x=str.charAt(i);
            map.put(x,map.getOrDefault(x,0)+1);
        }
        
        for(int i=0;i<order.length();i++){
            char x=order.charAt(i);
            if(map.containsKey(x)){
                int t=map.get(x);
                while(t-->0){
                    ans.append(x);
                }
                map.remove(x);
            }
        }
        
        for(char x:map.keySet()){
            int t=map.get(x);
            
            while(t-->0){
                ans.append(x);
            }
        }
        return ans.toString();
    }
}