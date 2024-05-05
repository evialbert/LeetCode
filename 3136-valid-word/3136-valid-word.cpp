class Solution {
public:
  bool isValid(string word) {
    if(word.size() < 3) return false;
    bool isVo = false, isCo = false;
    for(auto ch: word){
      if(ch >= '0' && ch <= '9') ;
      else if(ch >= 'A' && ch <= 'Z'){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') isVo = true;
        else isCo = true;
      } 
      else if(ch >= 'a' && ch <= 'z'){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') isVo = true;
        else isCo = true;
      }
      else return false; 
    }  
    return isVo && isCo;    
  }
};