class Solution {
    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        int[] mentor=new int[mentors.length];
        Arrays.fill(mentor,-1);
        return helper(0,mentor,students,mentors);
    }
    public int helper(int n,int[] mentor,int[][] students,int[][] mentors){
        if(n==students.length){
            int res=0;
            for(int val: mentor){
                res+=val;
            }
            return res;
        }
        int maxInSeg=0;
        for(int i=0;i<mentor.length;i++){
            if(mentor[i]==-1){
                int score=0;
                for(int j=0;j<mentors[0].length;j++){
                    if(students[n][j]==mentors[i][j]){
                        score++;
                    }
                }
                mentor[i]=score;
                int temp=helper(n+1,mentor,students,mentors);
                maxInSeg=maxInSeg>temp ? maxInSeg : temp;
                mentor[i]=-1;
            }
        }
        return maxInSeg;
    }
}