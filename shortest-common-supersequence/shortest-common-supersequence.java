class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        String ans="";
        int n=str1.length();
        int m=str2.length();
        String[][]dp=new String[n+1][m+1];
      
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]="";
                }else if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1]+str1.charAt(i-1);
                }else{
                     dp[i][j]=dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j]:dp[i][j-1];
                }
                
            }
        }
      
        StringBuilder sb=new StringBuilder();
        int p1=0;
        int p2=0;
        for(int i=0;i<dp[n][m].length();i++){
            while(p1<n && str1.charAt(p1)!=dp[n][m].charAt(i)){
                sb.append(str1.charAt(p1));
                p1++;
            }
            while(p2<m && str2.charAt(p2)!=dp[n][m].charAt(i)){
                sb.append(str2.charAt(p2));
                p2++;
            }
            p1++;
            p2++;
            sb.append(dp[n][m].charAt(i));
        }
        sb.append(str1.substring(p1));
        sb.append(str2.substring(p2));
        return sb.toString();
    }
}