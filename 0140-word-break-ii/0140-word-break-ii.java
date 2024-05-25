class Solution {
    HashSet<String> dic;
    List<String> ans;
    LinkedList<String> builder;
    public List<String> wordBreak(String s, List<String> wordDict) {
        
        dic = new HashSet<String>(wordDict);
        ans = new LinkedList<String>();
        builder = new LinkedList<String>();
        buildAnswer(s);
        return ans;
    }
    
    public void buildAnswer(String s) {
        if (s.equals("")) {
            ans.add(String.join(" ", builder));
            return;
        }
        for(int i = 1; i < s.length()+1; i++) {
            var curr = s.substring(0, i);
            if (dic.contains(curr)) {
                builder.add(curr);
                buildAnswer(s.substring(i));
                builder.removeLast();
            }
        }
    }
}