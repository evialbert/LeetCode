class TreeAncestor {
private:
    vector<int>parent;
    vector<vector<int>>mem;
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->parent=parent;
        mem=vector<vector<int>>(n,vector<int>(log2(n)+1,-1));
        for(int i=0;i<n;i++){
            mem[i][0]=this->parent[i];
        }
        for(int j=1;j<mem[0].size();j++){
            for(int i=0;i<n;i++){
                int first=mem[i][j-1];
                if(first!=-1){
                    mem[i][j]=mem[first][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        while(node!=-1 and k){
            int pos=log2(k&(-k));
            k-=k&(-k);
            node=mem[node][pos];
        }
        return node;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */