class Solution {
public:
    string multiply(string s1,string s2){
        if(s1=="0" or s2=="0") return 0;
        int m=s1.size(),n=s2.size();
        vector<int> res(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                res[i+j+1]+=(s1[i]-'0')*(s2[j]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        }
        int i=0;
        while(res[i]==0) i++;
        string ans="";
        while(i<res.size()) ans+=to_string(res[i++]);
        return ans;
    }
    string categorizeBox(int length, int width, int height, int mass) {
        string x=multiply(to_string(length),to_string(width));
        string y=multiply(x,to_string(height));
        bool v=(stoll(y)>=1e9);
        bool a=(length>=10000 or width>=10000 or height>=10000 or v);
        bool b=(mass>=100);
        cout<<a<<" "<<b<<" "<<v<<" "<<y<<endl;
        if(a and b) return "Both";
        else if(!a and !b) return "Neither";
        else if(a and !b) return "Bulky";
        else if(!a and b) return "Heavy";
        return "";
    }
};