class Solution {
    int fun(int n,int ind,int pos[],char arr[])
    {
        if(ind==arr.length)
            return 0;
        if(arr[ind]=='R'&&pos[1]+1<n)
            return 1+fun(n,ind+1,new int[]{pos[0],pos[1]+1},arr);
        else if(arr[ind]=='L'&&pos[1]-1>=0)
            return 1+fun(n,ind+1,new int[]{pos[0],pos[1]-1},arr);
        else if(arr[ind]=='U'&&pos[0]-1>=0)
            return 1+fun(n,ind+1,new int[]{pos[0]-1,pos[1]},arr);
        else if(arr[ind]=='D'&&pos[0]+1<n)
            return 1+fun(n,ind+1,new int[]{pos[0]+1,pos[1]},arr);
        else
            return 0;
    }
    public int[] executeInstructions(int n, int[] pos, String s) {
        
        int i,j,len=s.length();
        int ans[]=new int[len];
        for(i=0;i<len;i++)
            ans[i]=fun(n,0,pos,s.substring(i,len).toCharArray());
        return ans;
    }
}