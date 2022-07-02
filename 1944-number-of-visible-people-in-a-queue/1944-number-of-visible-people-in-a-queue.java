class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int res[]=new int[heights.length];
        Stack<int[]>stack=new Stack<>();//monotonic stack array consists of height,index
        for(int i=0;i<heights.length;i++)
        {
            int h=heights[i];//current present height
            while(!stack.isEmpty() && stack.peek()[0]<h)//if the top element height is less compared to current height..
                //i.e not monotically increasing hence pop it..
                //and before poping as the immediate prevH element can view the curr height element 
                //so increment the prevH element..
                //short ele
            {
                int prevH=stack.pop()[1];
                res[prevH]++;
            }
            if(!stack.isEmpty())//if its completely increasing no issues just get along and increment the indexth element 
                //previous tall can view so increment prevH
            {
                res[stack.peek()[1]]++;
            }
            stack.push(new int[]{h,i});//if stack is empty push with current height and position index value
        }
        return res;//return result with incremented values
    }
}