class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        sort(intervals.begin(), intervals.end()); 
        int ans=0;
        for (auto inter: intervals) {
            int start= inter[0], end= inter[1]; 
            if (pq.size() < 1 or pq.top() > start) 
                ans++; 
            else pq.pop(); 
            pq.push(end+1);
        }
        return ans;
        
        
    }
};