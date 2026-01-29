class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        string s=to_string(n);
        int sum=0,count=0;
        string p;

        for(char c:s){
            if(c!='0'){
                count++;
            char a=c;
            p.push_back(c);
            int d=a-'0';
            sum+=d;}}
            if(count==0) return 0;
        long long w=stoi(p);
        ans=w*sum;
        return ans;
    }
};