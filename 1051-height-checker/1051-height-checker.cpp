class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
            sort(expected.begin(),expected.end());
        if(expected == heights)
            return 0;
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i])
                count++;
        }
        return count;
    }
};