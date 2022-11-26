class Solution {
    int ans;
    vector<vector<int>> adj;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        ans = 0;
        adj.assign(n, {});
        for(int i=1; i<n; ++i){
            int p = parent[i];
            adj[p].push_back(i);
        }
        
        findLen(0, s);
        
        return ans;
    }
    
    
    // It returns max continuous len of a path with different chars
    int findLen(int node, string &s){
        // In worst case when all children have same char as par
        // we return 1, i.e , par's node's length
        int curLen = 1; // max continuous len of alternate chars with this node included
        
        // We need to keep track of max len from any 2 children, to form a path here
        // leftLen + Node (len=1) + rightLen
        // here left and right are 2 max lengths
        
        int top1 = 0, top2 = 0; // to keep track of 2 max lengths
        for(auto adNode: adj[node]){
            auto adLen = findLen(adNode, s);
            
            // If child and parent have same char skip it
            if(s[adNode]==s[node]) continue;
            
            if(adLen>top1){
                top2 = top1;
                top1 = adLen;
            }else if(adLen>top2){
                top2 = adLen;
            }
        }
        
        curLen = 1 + top1;
        int extend = 1 + top1 + top2;
        ans = max({ans, curLen, extend});
        
        return curLen;
    }
};