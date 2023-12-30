class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int[][]matrix=new int[26][26];
        for(int i=0;i<26;i++){
            Arrays.fill(matrix[i],(int)(1e9));
            matrix[i][i]=0;
        }
        for(int i=0;i<cost.length;i++){
            matrix[original[i]-'a'][changed[i]-'a']=Math.min(cost[i],matrix[original[i]-'a'][changed[i]-'a']);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(matrix[i][k]==1e9 || matrix[k][j]==1e9)continue;
                    matrix[i][j]=Math.min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        long ans=0;
        for(int i=0;i<source.length();i++){
            if(matrix[source.charAt(i)-'a'][target.charAt(i)-'a']==1e9){
                return (long)(-1);
            }else{
                ans+=matrix[source.charAt(i)-'a'][target.charAt(i)-'a'];
            }
        }
        return ans;
    }
}