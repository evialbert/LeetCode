class Solution {

    public int[] constructRectangle(int area) {

        int i=(int)Math.sqrt(area);

        int[] result=new int[2];

        for(;i>1;i--){

            if(area%i==0)

                break;

        }

        int j=area/i;

        if(i<j){

            result[0]=j;

            result[1]=i;

            return result;

        }else{

            result[0]=i;

            result[1]=j;

            return result;

        }

        

    }

}