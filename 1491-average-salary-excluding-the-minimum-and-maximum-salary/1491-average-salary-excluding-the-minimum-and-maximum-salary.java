class Solution {
    public double average(int[] salary) {
        Arrays.sort(salary);
        double sum=0;
        int i=0;
        int l=salary.length;
        for(i=1;i<l-1;i++)
            sum+=(double)salary[i];
        return sum/(l-2);
         
    }
}