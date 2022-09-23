class Solution {
 public List<Integer> goodDaysToRobBank(int[] security, int time) {
    List<Integer>ls=new ArrayList<>();
        int []increasingArr=new int[security.length];
        int []decreasingArr=new int[security.length];

        for(int i=0;i<security.length;i++) {
            if(i==0) {
                decreasingArr[i]=1;
            }
            else if(security[i-1]>=security[i])
            {
                decreasingArr[i]=1+decreasingArr[i-1];
        }
            else{
                decreasingArr[i]=1;
            }

    }
        for(int i=security.length-1;i>=0;i--)
        {
            if(i==security.length-1)
            {
                increasingArr[i]=1;
            }
            else if(security[i+1]>=security[i])
            {
                increasingArr[i]=1+increasingArr[i+1];
            }
            else{
                increasingArr[i]=1;
            }

        }

        for(int i=0;i<security.length;i++)
        {
            if(increasingArr[i]>time&&decreasingArr[i]>time)
            {
                ls.add(i);
            }
            
        }
        return ls;

}
       

    }