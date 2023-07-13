class Solution {
public:
    bool check;
    void dfs(vector<int> &visi, vector<int> &dfsvisi, int node, vector<vector<int>> &mat){
        visi[node] = 1;
        dfsvisi[node] = 1;
        for(int i=0; i<mat.size(); i++){
            if(mat[node][i] == 1) {
                if(dfsvisi[i] == 1) {
                    check = false;
                    break;}
                if(visi[i] == 0) dfs(visi, dfsvisi, i, mat);}}
        dfsvisi[node] = 0;}
    
    bool canFinish(int num, vector<vector<int>>& edge) {
        vector<vector<int>> mat(num+1, vector<int> (num+1, 0));
        vector<int> visi(num+1, 0), dfsvisi(num+1, 0);
        for(int i=0; i<edge.size(); i++) mat[edge[i][0]][edge[i][1]] = 1;
        check = true;
        for(int i=0; i<visi.size(); i++) if(visi[i] != 1) dfs(visi, dfsvisi, i, mat);
        return check;}};