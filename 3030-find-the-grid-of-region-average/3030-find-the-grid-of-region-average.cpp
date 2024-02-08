class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<vector<int>>> res(n, vector<vector<int>>(m));
        
        vector<int> indx = {0, -1, +1, 0};
        vector<int> indy = {-1, 0, 0, +1};
        for(int i = 0; i < n - 2; i++){
            for(int j = 0 ; j < m - 2; j++){
                int sum = 0;
                int c = 0;
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        for(int k = 0; k < 4; k++){
                            if(x + indx[k] >= i && x + indx[k] < i + 3 && y + indy[k] >= j && y + indy[k] < j + 3){
                                if(abs(image[x][y] - image[x + indx[k]][y + indy[k]]) > threshold){c = 1; break;}
                            }
                        } if(c == 1) break;
                        else sum += image[x][y];
                    } if(c == 1) break;
                } if(c == 1) sum = 0;
                else{
                    for(int p = i; p < i + 3; p++){
                    for(int q = j; q < j + 3; q++){
                        res[p][q].push_back(sum/9);
                    }
                }  
            }
        }
    }
        
        vector<vector<int>> ans(n, vector<int>(m));
                    for(int x = 0; x < n; x++){
                    for(int y = 0; y < m; y++){
                        int z = res[x][y].size();
                        int tt = 0;
                        for(auto it : res[x][y]) tt += it;
                        if(z == 0) ans[x][y] = image[x][y];
                        else ans[x][y] = tt/z;
                    }
                } return ans;
    }
};