class Solution {
    public String getHappyString(int n, int k) {
        List<String> res = new ArrayList<>();
        backtrack(new char[]{'a','b','c'},n,res,new StringBuilder());
        return res.size()<k?"":res.get(k-1);
    }
    
    public void backtrack(char[] arr,int n,List<String> res, StringBuilder sb)
    {
        if(sb.length()==n)
        {
            res.add(sb.toString());
            return;
        }
        for(int i=0;i<arr.length;i++)
        {if(sb.length()!=0 && sb.charAt(sb.length()-1)==arr[i])continue;
            backtrack(arr,n,res, sb.append(arr[i]));
            sb.deleteCharAt(sb.length()-1);
        }
    }  
}