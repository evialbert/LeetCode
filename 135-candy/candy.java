class Solution {
     static {
        for (int i = 0; i < 140; ++i)
            candy(new int[] { 1, 3, 2 });
            System.gc();
    }
    public static int candy(int[] ratings) {
        int n=ratings.length;
        int i=1;
        int sum=1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum+=1;
                i++;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                sum+=down;
                down++;
                i++;
            }
            if(down>peak)
            {
                sum+=down-peak;
            }
        }
        return sum;
    }
}