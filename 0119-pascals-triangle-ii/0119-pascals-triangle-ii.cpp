class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex+1, 0);
        output[0] = 1;
        for(int i=0; i<rowIndex; i++){
            for(int j=i+1; j>=1; j--){
                output[j] += output[j-1];
            }
        }
        return output;
    }
};
