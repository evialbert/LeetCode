class Solution {
public:
    long long solve(string &str,string &inputSuffix,int limit){
        if(str.length()<inputSuffix.length()){
            return 0;
        }
        long long count=0;
        string trailString=str.substr(str.length()-inputSuffix.length());
        int remainL=str.length()-inputSuffix.length();

        for(int i=0;i<remainL;i++){
            int digit=str[i]-'0';

            if(digit<=limit){
                count+=digit*pow(limit+1,remainL-i-1);
            } else{
                count+=pow(limit+1,remainL-i); //5^pos
                return count;
            }
        }
        if(trailString>=inputSuffix) count += 1;
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr=to_string(start-1);
        string finishStr=to_string(finish);
        return solve(finishStr,s,limit)-solve(startStr,s,limit);
    }
};