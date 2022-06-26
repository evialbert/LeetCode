class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long sum=0;
        for(int i:chalk) sum+=(long)i;
        //remaining chalks after full distribution to all students in class
        long after=k%sum;
        sum=0;
        for(int i=0;i<chalk.length;i++){
            sum+=(long)chalk[i];
            if(sum>after) return i;
        }
        return chalk.length-1;
    }
}