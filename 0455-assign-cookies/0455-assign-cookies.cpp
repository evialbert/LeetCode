class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gsize=g.size();
        int ssize=s.size();
        int p1=0;int p2=0;int count=0;
        while(p1<gsize && p2<ssize)
        {
            if(g[p1]<=s[p2])
            {
                p1++;
                p2++;
                count++;
            }
            else if(g[p1]>s[p2])
            {
                p2++;
            }
            else
            {
                p1++;
            }
            //count++;
        }
        return count;
    }
};