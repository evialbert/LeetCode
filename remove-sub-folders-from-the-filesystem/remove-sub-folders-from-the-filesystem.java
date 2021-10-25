class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
		
        List<String> res = new ArrayList<>();
        HashSet<String> hs = new HashSet<>();
        
        for(int i=0; i<folder.length; i++){
            String[] str = folder[i].split("/");
            String temp = "";
            boolean contains = false;
            for(int j=0; j<str.length; j++){
                temp += str[j]+" ";
                if(hs.contains(temp)){
                    contains = true;
                    break;
                }
            }
            if(!contains){
                hs.add(temp);
                temp = temp.replaceAll(" ","/");
                temp = temp.substring(0, temp.length()-1);
                res.add(temp);
            }
        }
        return res;
    }
}