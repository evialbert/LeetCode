class Solution {
public:
    bool is_upper(char c){
        if(c>=65 && c<=90)  return true;
        return false;
    }
    bool is_lower(char c){
        if(c>=90 && c<=122)  return true;
        return false;
    }
    int numberOfSpecialChars(string word) {
        int count = 0;
        unordered_map<char, pair<int, int>> upper_mp;
        unordered_map<char, int> lower_mp;
        for(int i=0;i<word.size(); i++){
            if(is_upper(word[i])){
                if(upper_mp.find(word[i])!=upper_mp.end()){
                    upper_mp[word[i]].second = i;
                }
                else{
                    upper_mp.insert({word[i], {i, i}});
                }
            }
            else{
                lower_mp[word[i]] = i;
            }
        }
        
        for(int i=0;i<word.size();i++){
            if(is_lower(word[i]) && lower_mp.find(word[i])!=lower_mp.end()){
                if( (upper_mp.find(toupper(word[i])) != upper_mp.end()) && (lower_mp[word[i]] < upper_mp[toupper(word[i])].first) && (lower_mp[word[i]] < upper_mp[toupper(word[i])].second)  ){
                    count++;
                    lower_mp.erase(word[i]);
                    
                }
            }
        }
        
        return count;
    }
};