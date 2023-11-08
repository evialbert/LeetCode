class Solution {
public:
    
    int val(int x, int y, vector<vector<int>>&img){
        if(x < 0 || y < 0) return -1;
        if(x >= img.size() || y >= img[0].size()) return -1;
        return img[x][y];
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                int sum = 0;
                int num = 0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        int temp = val(i-k, j-l, img);
                        if(temp == -1) num--;
                        else sum += temp;
                        num++;
                    }
                }
                ans[i][j] = sum/num;
            }
        }
        return ans;
    }
};