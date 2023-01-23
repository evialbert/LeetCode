class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        for(int i = 0;i<s.length();i++){
            if(s[i] >=97 && s[i]<= 122){
                int no = s[i];                
                if((i + distance[no-97]+1) < s.length()){
                    if(s[i] == s[i+distance[no-97]+1]){
                        s[i+distance[no-97] +1] = '.';
                    }else
                        return false;
                }else
                    return false;
            }
        }
        return true;
    }
	};