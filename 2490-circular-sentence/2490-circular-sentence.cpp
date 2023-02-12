class Solution {
public:
    bool isCircularSentence(string str) {
        vector<string>v;
        stringstream s(str);
        string word;
        while(s>>word){
            v.push_back(word);
        }
        int n=v.size();
        if(n==1){
            return v[0][0]==v[0][v[0].size()-1];
        }
        for(int i=0;i<n-1;i++){
            int k=v[i].size();
            if(v[i][k-1]!=v[i+1][0]){
                return false;
            }
        }
        if(v[0][0]!=v[n-1][v[n-1].size()-1]){
            return false;
        }
        return true;
    }
};