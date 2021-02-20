class Solution {
    public String[] findWords(String[] words) {
        List<Character> firstRow = Arrays.asList('q','w','e','r','t','y','u','i','o','p');
        List<Character> secondRow = Arrays.asList('a','s','d','f','g','h','j','k','l');
        List<Character> thirdRow = Arrays.asList('z','x','c','v','b','n','m');
        List<Character> a = new ArrayList<Character>();
        List<Character> b = new ArrayList<Character>();
        List<Character> c = new ArrayList<Character>();
        a.addAll(firstRow);
        b.addAll(secondRow);
        c.addAll(thirdRow);
        
        ArrayList<String> result = new ArrayList<>();
       
        for(int i =0;i<words.length;i++){
          int count1=0,count2 =0;
            int count3=0;
            for(int j =0;j<words[i].length();j++){
                if(a.contains(Character.toLowerCase(words[i].charAt(j)))){
                    count1 +=1;
                    
                }else if(b.contains(Character.toLowerCase(words[i].charAt(j)))){
                    count2 +=1;
                    
                }else if(c.contains(Character.toLowerCase(words[i].charAt(j)))){
                    count3 +=1;
                  
                }
            }
           
            if((count1 == words[i].length()) || (count2 == words[i].length()) || (count3 == words[i].length())){
                 result.add(words[i]);
            }
        }
        String[] strArray = result.toArray(new String[result.size()]);
        return strArray;
    }
}