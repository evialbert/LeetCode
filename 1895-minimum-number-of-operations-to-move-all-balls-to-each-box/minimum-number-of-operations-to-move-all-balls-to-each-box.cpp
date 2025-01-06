class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sub = 0;
        int sum = 0;
        vector<int>res (boxes.size(), 0);
        for(int i = 0; i < boxes.size(); i++){
            if(boxes[i] == '1'){
                sub += 1;
                sum += i;
            }
        }
        if(boxes[0] == '1'){
            sub -= 2;
        }
        int pos = 0;
        res[pos++] = sum;
        for(int i = 1; i < boxes.size(); i++){
            sum = sum - sub;
            if(boxes[i] == '1'){sub-=2;}
            res[pos++] = sum;
        }
        return res;
    }
};