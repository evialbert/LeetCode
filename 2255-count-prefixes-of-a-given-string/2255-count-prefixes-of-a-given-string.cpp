class Solution {
private:
    int linear_search(vector<string>& words , string prefix){
        int count = 0;
        for(int i = 0 ; i < words.size() ; i++){
            if(prefix == words[i])
                count++;
        }
        return count;
    }
    
public:
    int countPrefixes(vector<string>& words, string s) {
        vector<string> prefix;
        int count = 0;
        
        for(int i = 1 ; i <= s.length() ; i++){
            prefix.push_back(s.substr(0,i));
        }
        
        
        for(int i = 0 ; i < prefix.size() ; i++){
            count = count + linear_search(words , prefix[i]);
        }
        
        return count;
    }
};