class Solution {
    Integer[] dp; 
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        
        Job[] jobs = new Job[startTime.length];
        
        for(int i=0; i < startTime.length;i++){ 
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(jobs, new Comparator<Job>(){ 
            public int compare(Job job1, Job job2){ 
                return job1.startTime - job2.startTime; 
            }
        });
        
        dp = new Integer[endTime.length];
        
        return recurse(0,jobs);
    }
    
    public int recurse(int pos, Job[] job){ 
        if(pos >= job.length){ 
            return 0; 
        }
        
        if(dp[pos]!=null) return dp[pos];

        int low = pos+1; 
        int high = job.length; 
        
        while(low < high){ 
            int mid = (low + high)/2;
            if(job[mid].startTime < job[pos].endTime){ 
                low = mid+1;
            } else { 
                high = mid;
            }
        }
                
        dp[pos] =  Math.max(recurse(pos+1, job), job[pos].profit +  recurse(low, job));
                
        return dp[pos];
    }
    
    class Job {
        int startTime; 
        int endTime; 
        int profit; 
        
        public Job(int start, int end, int profit){ 
            this.startTime = start; 
            this.endTime = end; 
            this.profit = profit; 
        }
    }
}