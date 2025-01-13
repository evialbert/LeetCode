class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string ag=to_string(n);
        int i=1;
        while(i<ag.size() && ag[i]>=ag[i-1]){
            i++;
        }
        while(i>0 && i<ag.size() && ag[i-1]>ag[i]){
            ag[i-1]--;
            i--;
        }
        for(int j=i+1;j<ag.size();j++){
            ag[j]='9';
        }
        return stoi(ag);
    }
};