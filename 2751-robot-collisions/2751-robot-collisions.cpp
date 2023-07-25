class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hel, string dir) {
        map<int,int,greater<int>> r;
        map<int,int> l;
        int n = pos.size();
        for(int i=0;i<n;i++)
        {
            if(dir[i]=='L')
            {
                l[pos[i]] = hel[i];
            }
            else
                r[pos[i]] = hel[i];
        }
        
        auto it1 = r.begin();
        while(it1!=r.end())
        {
            auto it2 = l.lower_bound(it1->first);
            if(it2!=l.end())
            {
                if(it1->second>it2->second)
                {
                    it1->second--;
                    l.erase(it2);
                }
                else if(it1->second<it2->second)
                {
                    it2->second--;
                    it1->second = -1;
                    it1++;
                }
                else
                {
                    l.erase(it2);
                    it1->second = -1;
                    it1++;
                }
            }
            else
                it1++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(dir[i]=='L')
            {
                if(l.find(pos[i])!=l.end())
                {
                    if(l[pos[i]]>0)
                        ans.push_back(l[pos[i]]);
                }
            }
            else if(dir[i]=='R')
            {
                if(r.find(pos[i])!=r.end())
                {
                    if(r[pos[i]]>0)
                        ans.push_back(r[pos[i]]);
                }
            }
        }
        return ans;
    }
};