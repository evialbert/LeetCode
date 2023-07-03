class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length())return false;
        vector<int>mp(26,0);
        vector<int>mp1(26,0);
        int count = 0;  // count will be checking the number of 
        //unequal elements at particular index in both goal and s
        for(int i = 0 ; i < s.length();i++){
            mp[s[i]-'a']++;
            mp1[goal[i]-'a']++;
            if(goal[i]!=s[i])count++;
        }
        if(mp!=mp1)return false;
        else{
            if(s==goal){
                for(int i = 0 ; i < s.length();i++){
                    if(mp[s[i]-'a']>1)return true;
                }
                return false;
            }
            if(count==2)return true; // if count is 2 then 
            //only successfull swap is possible otherwise not
            return false;
        }
    }
};