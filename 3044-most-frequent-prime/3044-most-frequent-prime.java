class Solution {
    public boolean checkprime(int n){
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= Math.sqrt(n); i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    public void helper(int[][]mat,int i,int j,int a,int b,HashMap<Integer,Integer>map,int val){
        int n=mat.length;
        int m=mat[0].length;
        i=i+a;
        j=j+b;
        while(i<n && j<m && i>=0 && j>=0){
            val=val*10 +mat[i][j];
            i=i+a;
            j=j+b;
            if(val>10 && checkprime(val)){
            map.put(val,map.getOrDefault(val,0)+1);
            }
        }
    }
    public int mostFrequentPrime(int[][] mat) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int n=mat.length;
        int m=mat[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=mat[i][j];
                int delrow[]={0,0,1,-1,1,-1,-1,1};
                int delcol[]={1,-1,0,0,1,-1,1,-1};
                for(int k=0;k<8;k++){
                    helper(mat,i,j,delrow[k],delcol[k],map,temp);
                }
            }
        }
        int val=-1;
        int freq=0;
        for(Map.Entry<Integer,Integer>entry:map.entrySet()){
            if(entry.getValue()>freq){
                freq=entry.getValue();
                val=entry.getKey();
            }
            if(entry.getValue()==freq){
                val=Math.max(val,entry.getKey());
            }
        }
        return val;
    }
}