class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);

        string ans;

        while(s1.size() < 4){
            s1 = '0' + s1;
        }
        while(s2.size() < 4){
            s2 = '0' + s2;
        }
        while(s3.size() < 4){
            s3 = '0' + s3;
        }

        for(int i = 0; i < 4 ; i++){
            ans += min(s1[i],min(s2[i],s3[i]));
        }

        return stoi(ans);
    }
};