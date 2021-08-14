class Solution {
    public int[] movesToStamp(String stamp, String target) {
        List<Integer> reverseIndexList=new ArrayList<>();
        int len=target.length();
        // Approch :  reverse Processing 
        char[] curr=target.toCharArray();
        char[] targetStr=new char[len];
        Arrays.fill(targetStr,'*');
        
        while(!Arrays.equals(targetStr,curr)){
            int stampIdx=fetchStampIndex(curr,stamp);
            if(stampIdx<0){
                return new int[0];
            }else{
                update(curr,stampIdx,stamp);
            }
            reverseIndexList.add(stampIdx);
        }
        
        int[] ans=new int[reverseIndexList.size()];
        int size=ans.length;
        for(int i=0;i<reverseIndexList.size();i++){
            ans[i]=reverseIndexList.get(size-1-i);
        }
    
        return ans;
    }
    
    private void update(char[] curr,int i,String stamp){
        for(int j=0;j<stamp.length();j++) curr[i+j]='*';
    }
    
    private int fetchStampIndex(char[] curr,String stamp){
        for(int i=0;i<=curr.length-stamp.length();i++){
            int s=0; // s: iterate over stamp
            int c=i; // c : iterate over curr
            boolean nonStar=false;
            while(s<stamp.length() && c<curr.length && (curr[c]=='*' || curr[c]==stamp.charAt(s))){
            if(curr[c]==stamp.charAt(s)) nonStar=true;
                s++;
                c++;
            }
            
            if(nonStar && s==stamp.length()){
                return i;
            }
        }
        return -1;
    }
}