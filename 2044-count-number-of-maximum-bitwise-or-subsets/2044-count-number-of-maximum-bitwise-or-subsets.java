class Solution 
{
    int count=0;
    int MaxOR=0;
    private void findSubsets(int ind,List<Integer> ds,int[] arr,int currentOR)
    {
        if(ind==arr.length)
        {
            if(currentOR>MaxOR)
            {
                MaxOR=currentOR;
                count=0;
            }
            else if(currentOR==MaxOR)
                count++;
            return;
        }
        ds.add(arr[ind]);
        findSubsets(ind+1,ds,arr,currentOR|arr[ind]);
        ds.remove(ds.size()-1);
        findSubsets(ind+1,ds,arr,currentOR);
    }
    public int countMaxOrSubsets(int[] nums) 
    {
        findSubsets(0,new ArrayList<>(),nums,0);
        return count+1;//+1 for first element
    }
}