class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int p=0,ans=0; 
        if(ruleKey.equals("type"))
            p=0;
        else if(ruleKey.equals("color"))
            p=1;
         else
            p=2;
             
         for(int i=0;i<items.size();i++)
         {
             if(items.get(i).get(p).equals(ruleValue))
                ans++;
         }
      return ans;
    }
}
