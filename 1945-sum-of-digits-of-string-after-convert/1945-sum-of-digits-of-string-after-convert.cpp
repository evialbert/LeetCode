class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(int i=0;i<s.length();i++){
            temp = temp + to_string(int(s[i])-97+1);
        }
        int sum=0;
        int ans=0;                    
         for(int i=0;i<k;i++){
         for(int i=0;i<temp.length();i++){
            sum=sum+int(temp[i]-'0');
             ans=sum;
        }
            temp.erase();
            temp = temp + to_string(sum);
            sum=0;
        }
        return ans;
    }
};