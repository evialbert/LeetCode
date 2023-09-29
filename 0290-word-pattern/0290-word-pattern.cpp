class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,vector<int>> mp1;
       map<string,vector<int>> mp2;
        int n1=p.size();
        for(int i=0;i<n1;i++){
            mp1[p[i]].push_back(i);
        }
        int n2=s.size();
        int k=0,j;
        string str="";
        for(int i=0;i<n2;i++){
            str="";
            for(j=i;j<n2;j++){
                if(s[j]==' '){
                    mp2[str].push_back(k);
                    k++;
                    break;
                }
                else
                    str+=s[j];
            }
            i=j;
        }
        if(n1!=k+1) return false;
        mp2[str].push_back(k);
        
        for(auto it1: mp1){
            vector<int> v1=it1.second;
            for(auto it2:mp2){
                vector<int> v2=it2.second;
                if(v1==v2){
                    mp2.erase(it2.first);
                    break;
                }
            }
        }
        if(mp2.size()==0) return true;
        return false;
    }
};