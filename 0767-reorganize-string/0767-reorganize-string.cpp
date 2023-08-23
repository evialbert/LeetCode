class Solution {
public:
    string reorganizeString(string s) {
        
        map<char,int> m;
        for(auto &i: s)
        {
            m[i]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto &it: m)
        {
            pq.push(make_pair(it.second,it.first));
        }
        
        string ans = "";
        
        // IMPORTANT CONDITION -> Once we have only a single element in the queue we breakout 
        while(pq.size() > 1)
        {
            char mostFreq = pq.top().second;
            pq.pop();
            char nextFreq = pq.top().second;
            pq.pop();
            
            ans += mostFreq;
            ans += nextFreq;
            
            if(m[mostFreq] - 1 > 0)
            {
                m[mostFreq] -= 1;
                pq.push(make_pair(m[mostFreq],mostFreq));
            }
            
            if(m[nextFreq] - 1 > 0)
            {
                m[nextFreq] -= 1;
                pq.push(make_pair(m[nextFreq],nextFreq));
            }
        }
        
        if(pq.size())
        {
            char lastChar = pq.top().second;
            if(m[lastChar] > 1)
                return "";
            else
                ans+=lastChar;
        }
        
        return ans;
        
        
    }
};