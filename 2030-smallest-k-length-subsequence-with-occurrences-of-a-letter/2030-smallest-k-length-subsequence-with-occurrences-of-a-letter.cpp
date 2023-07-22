class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int available=0;
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]==letter){
                available++;
            }
        }
        int seen=0;
        for(int i=0;i<s.size();i++){
            while(res.size() and res.back()>s[i] and res.size()+s.size()-i>k){
                if(res.back()==letter){
                    if(available+seen-1>=repetition){
                        res.pop_back();
                        seen--;
                    } else {
                        break;
                    }
                } else {
                    res.pop_back();
                }
            }
            if(s[i]==letter){
                seen++;
                available--;
            }
            res.push_back(s[i]);
        }
        string ans="";
        for(int i=0;i<res.size();i++){
            if(res[i]==letter and repetition>0 and k>0){
                repetition--;
                k--;
                ans.push_back(res[i]);
            } else if(k-repetition>0){
                k--;
                ans.push_back(res[i]);
            }
        }
        return ans;
    }
};