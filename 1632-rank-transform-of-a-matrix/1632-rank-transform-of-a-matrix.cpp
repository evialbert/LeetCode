class Solution {
public:    
    
    int parent[250009]; // node parents 
    int rank[250009];   // node ranks
    int mat1DIndex[500][500];   // 2D to 1D index mapping 
    int mat2DIndex[250009][2];  // 1D to 2D index mapping
    int rowv[500];  // rows rank
    int colv[500];  // cols rank
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int limit = m * n;

        // tracks same values in rows and columns
        unordered_map<int,vector<int>>rowlist[m];
        unordered_map<int,vector<int>>collist[n];
        
        // result vector
        vector<vector<int>>res(m,vector<int>(n,0));
        
        // store values in sorted order and their positions 
        map<int,vector<pair<int,int>>>tracks;
        int c = 0;
        for(int i=0;i<m;i++)
        {
            rowv[i] = 1;    // initial row rank 1
            for(int j=0;j<n;j++)
            {
                colv[j] = 1;    // initial col rank 1
                parent[c] = c;
                rank[c] = 0;
                mat1DIndex[i][j] = c;
                mat2DIndex[c][0] = i;
                mat2DIndex[c][1] = j;
                tracks[mat[i][j]].push_back({i,j});
                rowlist[i][mat[i][j]].push_back(j);
                collist[j][mat[i][j]].push_back(i);
                c++;
            }
        }        
        
        int x,y;
        int v,p;
        
        // loop through smallest to highest values and find the rank of the connected components
        for(auto &it : tracks)
        {
            v = it.first; 
            
            // loop throough all positions of the same value and unify them with their row or col same element
            for(auto &vt : it.second)
            {
                x = vt.first;
                y = vt.second;

                // unify with itself
                p = find(mat1DIndex[x][y]);
                rank[p] = max({rank[p],rowv[x],colv[y]});
                
                // unify with one other row position element
                for(auto &t : rowlist[x][v])
                {                        
                    if(t==y)continue;
                    unify(mat1DIndex[x][y],mat1DIndex[x][t]);
                    break;
                }                        
                
                // unify with one other col position element
                for(auto &t : collist[y][v])
                {
                    if(t==x)continue;
                    unify(mat1DIndex[x][y],mat1DIndex[t][y]);
                    break;
                }                        
            }
                
            // update ranks of the connected components and row and col rank 
            for(auto &vt : it.second)
            {
                x = vt.first;
                y = vt.second;
                res[x][y] = rank[find(mat1DIndex[x][y])];
                rowv[x] = res[x][y]+1;  
                colv[y] = res[x][y]+1;
            }
        }
        
        return res;
    }
    
    int find(int t)
    {
        if(parent[t]==t) return t;        
        return parent[t] = find(parent[t]);
    }
    
    void unify(int t1, int t2)
    {
        int p1 = find(t1);
        int p2 = find(t2);
        
        if(p1==p2) return;
        
        // make min value as the parent of max value
        parent[max(p1,p2)] = min(p1,p2);
        
        // get max rank from p1, p2, rowv[t1], rowv[t2], colv[t1], colv[t2]
        rank[min(p1,p2)] = max({rank[p1],rank[p2],rowv[mat2DIndex[t1][0]],colv[mat2DIndex[t1][1]],rowv[mat2DIndex[t2][0]],colv[mat2DIndex[t2][1]]});
    }

};