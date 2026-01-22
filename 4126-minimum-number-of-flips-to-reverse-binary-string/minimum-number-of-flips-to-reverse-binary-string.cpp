class Solution {
public:
    vector<int> rbinary(int n){
        vector<int> ans;
        while(n>0){
            ans.push_back(n%2);
            n/=2;
        }
        return ans;
    }
    int minimumFlips(int n) {
        if(n==0) return 0;
        vector<int> make =  rbinary(n);
        vector<int> make2 = rbinary(n);
        reverse(make2.begin(),make2.end());
        int ans = 0;
        for(int i = 0;i<make.size();i++){
            if(make2[i]!=make[i]) ans++;
        }
        
        return ans;
    }
};