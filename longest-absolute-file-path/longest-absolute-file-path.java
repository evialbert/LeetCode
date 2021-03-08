class Solution {
  public int lengthLongestPath(String input) {
        Map<Integer,Integer> m = new HashMap<>();
        int n = input.length(),ans=0,currLen=0,level=0;
        boolean isFile = false;
        for(int i=0;i<n;i++) {
            char ch = input.charAt(i);
            if(ch!='\n' && ch!='\t') {
                if(ch=='.') isFile = true;
                currLen++;
            }
            if(ch=='\n') {
                int prevLevelSize = m.getOrDefault(level-1,0);
                m.put(level,currLen+prevLevelSize+1);
                if(isFile) {
                    ans = Math.max(ans,currLen+prevLevelSize);
                }
                currLen = 0;
                isFile = false;
                level = 0;       
            }
            if(ch=='\t') level++;
        }
        int prevLevelSize = m.getOrDefault(level-1,0);
        m.put(level,currLen+prevLevelSize);
        if(isFile) {
           ans = Math.max(ans,currLen+prevLevelSize);
        }
        return ans;
    }
}