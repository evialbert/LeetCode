class Solution {
public:
    int addDigits(int num) {
        int ans;
        string temp=to_string(num);
        while(temp.length()>1){
            int val = 0;
            for(int i=0;i<temp.length();i++){
                val += temp[i]-'0';
            }
            temp = to_string(val);
        }
        return stoi(temp);
    }
};