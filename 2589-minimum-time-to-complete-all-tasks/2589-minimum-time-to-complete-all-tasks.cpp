class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks)
    {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        map<int,bool> used;
        int count=0;
        for(auto &v:tasks)
        {
            int usedtime=0;
            for(int i=v[0];i<=v[1];i++)
            {
                if(used.count(i))
                    usedtime++;
            }
            for(int i=v[1];usedtime<v[2];i--)
            {
                if(!used.count(i))
                {
                    usedtime++;
                    used[i]=true;
                    count++;
                }
            }
        }
        return count;
        
    }
};