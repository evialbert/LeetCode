class Solution {
public:
    string ans;
    void f(string& p,vector<int>&v,string &target,char ch,bool big){
        if(p.length()==target.length()/2){
            string k = p;
            string g = p;
            reverse(k.begin(),k.end());
            if(target.length()%2==1){
                g += ch;
            }
            g += k;
            if(target<g){
                if(ans=="") ans = g;
                else ans = min(ans,g);
            }
            return;
        }
        int idx = p.length();
        for(int i=0;i<26;i++){
            if(v[i]>0){
                if(!big and i+'a'<target[idx]) continue;
                p += i + 'a';
                v[i]--;
                bool nb = big or (i+'a'>target[idx]);
                f(p,v,target,ch,nb);
                if(ans!="") return;
                p.pop_back();
                v[i]++;
            }
        }
    }
    string lexPalindromicPermutation(string s, string target) {
        ans = "";
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        char ch = ' ';
        for(int i=0;i<26;i++){
            if(v[i]%2==1){
                if(ch==' ') ch = i+'a';
                else return "";
            }
        }
        for(int i=0;i<26;i++){
            if(v[i]%2==1) v[i]--;
            v[i] = v[i]/2;
        }
        string p = "";
        bool big = false;
        f(p,v,target,ch,big);
        return ans;
    }
};