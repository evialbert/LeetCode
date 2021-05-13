class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        
        for (String path : paths) {
            
            String[] strArray = path.split(" ");
            String pathName = strArray[0];
            
            for (int i = 1; i < strArray.length; i++) {
                String s = strArray[i];
                int index = s.indexOf("(");
                String fileName = s.substring(0, index);
                String content = s.substring(index + 1, s.length() -1);
                
                if (map.containsKey(content)) {
                    map.get(content).add(pathName + "/" + fileName);
                } else {
                    List<String> list = new ArrayList<>();
                     list.add(pathName + "/" + fileName);
                    map.put(content, list);
                }         
            }
        }
        
        for (List<String> list : map.values()) {
            if (list.size() > 1) {
                res.add(list);
            }
        }
        
        return res;
        
    }
} 