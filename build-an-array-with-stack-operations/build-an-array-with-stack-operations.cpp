class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> inputArray(n);
        vector<string> result;
        int j=1;
        for(int i=0;i<target.size();){
            if(target[i]==j){
                j++;
                i++;
                result.push_back("Push");
            }else{
                j++;
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};