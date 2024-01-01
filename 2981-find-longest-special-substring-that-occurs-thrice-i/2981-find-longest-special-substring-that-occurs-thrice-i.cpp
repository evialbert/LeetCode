class Solution {
public:
    int maximumLength(string s) {
        vector<string>ans;
        unordered_map<string,int>mapping;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                string temp="";
                for(int k=i;k<=j;k++){
                    temp+=s[k];
                    }
                mapping[temp]++;
            }
        }
        int maxi=-1;
        for(auto i : mapping){
            if(i.second>=3){
                char ch=i.first[0];
                bool  flag=true;
                for(auto j : i.first){
                    if(j!=ch){
                        flag=false;
                    }
                }
                int t=i.first.length();
                if(flag)
                maxi=max(maxi,t);
            }
        }
        return maxi;
    }
};