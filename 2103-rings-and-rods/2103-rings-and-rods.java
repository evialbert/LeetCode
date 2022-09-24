class Solution {
    public int countPoints(String rings) {
        HashMap<Character,String> map = new HashMap<>();
        for(int i=0;i<rings.length();i=i+2){
            if(!map.containsKey(rings.charAt(i+1)))
                map.put(rings.charAt(i+1),Character.toString(rings.charAt(i)));
            else{
                String str = map.get(rings.charAt(i+1));
                str=str+Character.toString(rings.charAt(i));
                map.replace(rings.charAt(i+1),str);
            }
        }
        int count=0;
        for(Map.Entry m: map.entrySet()){
            String st = (String)m.getValue();
            if(st.contains("R") && st.contains("G") && st.contains("B"))
                count++;
        }
        return count;
    }
}