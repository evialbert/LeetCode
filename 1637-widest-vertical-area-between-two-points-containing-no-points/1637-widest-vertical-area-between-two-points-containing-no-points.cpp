class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    priority_queue<pair<int,int>> pq;
    
    for(auto x:points){
        pq.push(make_pair(x[0],x[1]));
        
    }
    
    int ans=INT_MIN;
    int prev=pq.top().first;
    pq.pop();
    while(!pq.empty()){
        int current=pq.top().first;
        ans=max(ans,prev-current);
        pq.pop();
        prev=current;
        
        
    }
    return ans;
    
}
};