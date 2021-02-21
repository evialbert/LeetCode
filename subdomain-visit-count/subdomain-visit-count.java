class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        List<String> result = new ArrayList<>();
        for(String s:cpdomains){
            int indexOfSpace = s.indexOf(' ');
            Integer count = map.get(s.substring(indexOfSpace+1));
            Integer add = Integer.parseInt(s.substring(0,indexOfSpace));
            if(count==null){
                map.put(s.substring(indexOfSpace+1), add);
            }else{
                map.put(s.substring(indexOfSpace+1), count+add);
            }
            List<Integer> indexOfPoint = new ArrayList<>();
            for(int i=s.length()-1;i>indexOfSpace;i--){
                if(s.charAt(i)=='.'){
                    indexOfPoint.add(i);
                }
            }
            for(int i=0;i<indexOfPoint.size();i++){
                String domainName = s.substring(indexOfPoint.get(i)+1);
                count = map.get(domainName);
                if(count==null){
                    map.put(domainName, add);
                }else{
                    map.put(domainName, count+add);
                }
            }
        }
        for(String key:map.keySet()){
            result.add(map.get(key)+" "+key);
        }
        return result;
    }
}