class Solution {
    public double average(int[] salary) {
        int size = salary.length;
        int min=Integer.MAX_VALUE,max = 0;
        int total = 0;
        for(int i=0;i<size;i++){
            total+=salary[i];
            if(salary[i]<min)
                min = salary[i];
            if(salary[i]>max)
                max = salary[i];
        }
        
        total = total-max-min;
        return (double)total/(size-2);
            
    }
}