class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long>mp;
        int n=tasks.size();
        long long day=1;
        
        for (int i=0; i<n; i++)
        {
            if (mp.find(tasks[i])==mp.end())
            {
                mp[tasks[i]]=day;
                day++;
            }
            else{
                if (day> mp[tasks[i]]+space)
                {
                    mp[tasks[i]]=day;
                    day++;
                }
                else {
                    day= mp[tasks[i]]+ space+1;
                    mp[tasks[i]]=day;
                    day++;
                }
            }
        
        }
        return day-1;
        
    }
};