class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        map<char,int>pick,lastvisit;
        int l = garbage.size();
        for(int i=0;i<l;i++)
        {
            for(auto x : garbage[i])
            {
                pick[x]++;
            }
        }
        for(int i=0;i<l;i++)
        {
            for(auto x : garbage[i])
            {
                lastvisit[x] = i;
            }
        }
        int totaltime = 0;
        for(auto x : pick)
        {
            totaltime+=x.second;
        }
        for(int i=0;i<travel.size()-1;i++)
        {
            travel[i+1]+=travel[i];
        }
        for(auto x : lastvisit)
        {
            if(x.second-1>=0)
            {
                totaltime+=travel[x.second-1];
            }
        }
        return totaltime;
    }
};