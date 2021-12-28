class Node{
    int sum;
    int val;
    Node(int sum,int val){
        this.sum=sum;
        this.val=val;
    }
}
class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
       ArrayList<Node> temp=new ArrayList<>();
        for(int i=nums.size()-1;i>=0;i--)
           for(int j=nums.get(i).size()-1;j>=0;j--)
               temp.add(new Node(i+j,nums.get(i).get(j)));
            
        
        Collections.sort(temp,(a,b)->a.sum-b.sum);
        int result[]=new int[temp.size()];
        for(int i=0;i<temp.size();i++)
            result[i]=temp.get(i).val;
        return result;       
    }
}