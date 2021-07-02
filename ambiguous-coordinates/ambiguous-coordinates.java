class Solution {
    public List<String> xPoss, ans;
    public List<String> ambiguousCoordinates(String s) {
        ans = new ArrayList<>();   
        for(int i = 2; i < s.length() - 1; i++){
            String[] str = {s.substring(1, i), s.substring(i, s.length() - 1)};
            xPoss = new ArrayList<>();
            for(int j = 0; j < 2; j++){
                if(xPoss.size() > 0 || j == 0) placDec(str[j], j);
            }
        }
        return ans;
    }
    public void placDec(String str, int lr){
        if(str.length() == 1 || str.charAt(0) != '0')
            process(str, lr);
        if(str.length() > 1 && str.charAt(str.length() - 1) != '0') 
            process(str.substring(0, 1) + "." + str.substring(1), lr);
        if(str.length() > 2 && str.charAt(0) != '0' && str.charAt(str.length() - 1) != '0')
            for(int j = 2; j < str.length(); j++)
                process(str.substring(0, j) + "." + str.substring(j), lr);
    } 
    public void process(String str, int lr){
        if(lr > 0){
          for (String x : xPoss)
                ans.add("(" + x + ", " + str + ")");
        }
        else xPoss.add(str);
    }
}