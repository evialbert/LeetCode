class Solution {
public:

    void solve(int &startNum,int &n,vector<int>&result){
        if(startNum > n)  return ;
        result.push_back(startNum);
        for(int append=0;append<=9;append++){
            int newNum = startNum*10+append;
            if(newNum > n)  return;
            solve(newNum,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int startNum=1;startNum<=9;startNum++)
           solve(startNum,n,result);
        return result;
    }
};