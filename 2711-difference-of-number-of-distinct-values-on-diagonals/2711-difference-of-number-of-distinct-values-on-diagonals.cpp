class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                set<int>s1,s2;
                for(int ri=i+1,rj=j+1;ri<m && rj<n;ri++,rj++){
                    s1.insert(grid[ri][rj]);
                }
                for(int li=i-1,lj=j-1;li>=0 && lj>=0;li--,lj--){
                    s2.insert(grid[li][lj]);
                }
                int val=s1.size()-s2.size();
                temp.push_back(val<0?-val:val);                                
            }
            ans.push_back(temp);
        }        
        return ans;
    }
};