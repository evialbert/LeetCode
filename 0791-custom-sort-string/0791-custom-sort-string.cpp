class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char i : s)
            mp[i]++;
        s.clear();
        for(int i=0; i<order.size(); i++)
        {
            if(mp.find(order[i]) != mp.end())
            {
                // int c = mp[order[i]];
                while(mp[order[i]]--)
                    s.push_back(order[i]);
            }
            else
                continue;
        }
        for(auto i : mp)
        {
            if(i.second>0)
            {
                while(i.second--)
                    s.push_back(i.first);
            }
        }
        return s;
    }
};