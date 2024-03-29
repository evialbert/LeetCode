class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> v1,v2;
        for(int i=0; i<matrix.size();i++){           
            for(int j=0; j<matrix[i].size();j++){
                if(matrix[i][j]==0) {
                    v1.insert(i);
                    v2.insert(j);
                }
            }
        }

        for(int i=0; i<matrix.size();i++){           
            for(int j=0; j<matrix[i].size();j++){
                if(v1.count(i) || v2.count(j)) {
                    matrix[i][j]=0;
                }
            }
        }

    }
};