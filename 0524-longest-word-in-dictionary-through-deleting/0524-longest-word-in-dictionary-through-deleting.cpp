class Solution {
public:
    string findLongestWord(string s, vector<string>& arr) {
        
         string ans="";
         for(int i=0;i<arr.size();i++)
         {
             string currstr=arr[i];
             
             int idx1=0;
             int idx2=0;
             
             while(idx1<currstr.length() and idx2<s.length())
             {
                 if(currstr[idx1]==s[idx2])
                 {
                     idx1++;
                     idx2++;
                 }
                 else
                 {
                     //delete from s
                     idx2++;
                 }
             }
             if(idx1>=currstr.length()) 
             {
                 if(currstr.length()>ans.length())
                 {
                     ans=currstr;
                 }
                 else if(currstr.length()==ans.length() and currstr<ans)
                 {
                    ans=currstr;
                 }
             }
             
         }
        return ans;
    }
};