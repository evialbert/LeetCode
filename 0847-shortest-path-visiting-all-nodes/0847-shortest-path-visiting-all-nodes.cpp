class Solution {
public:
// Class to carry three values at a time
    class node{
        public:
        int val;// on which current node we are standing
        int mask; // mask of that node
        int cost;// cost of path explore by this node
        node(int n,int m,int c){
            val = n,mask = m,cost = c;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();// total number of nodes present
        int all = (1 << n) - 1;

        queue<node> q;// queue of class node type
        
        // set to take care which path we have already visited
        set<pair<int,int>> vis;

        // we don't know which node will give us shortest path so intially for all nodes we will store in our queue
        for(int i = 0;i<n;i++){
            node thisNode(i,1<<i,1);// make a node
            q.push(thisNode);// push node into our queue
            vis.insert({i,1<<i});// also them into our set
        }

        // Implementing BFS
        while(!q.empty()){// until queue is not empty
            node curr = q.front();// extracting top node
            q.pop();
            
            // if mask value becomes all, that means we have visited all of our nodes, so from here return cost - 1
            if(curr.mask == all) return curr.cost - 1;

            // if not, start exploring in its adjcant
            for(auto neighbour: graph[curr.val]){
                int newMask = curr.mask | (1<<neighbour);
                
                // if this path is not explored i.e
                // if it is not present in our set then,
                if(vis.find({neighbour,newMask}) == vis.end()){
                    node newNode(neighbour,newMask,curr.cost+1);
                    vis.insert({neighbour,newMask});
                    q.push(newNode);
                }
            }
        }
        //If no path exist then loop will eventually come out and return -1
        return -1;
    }
};