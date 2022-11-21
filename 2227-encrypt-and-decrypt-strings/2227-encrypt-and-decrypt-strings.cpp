class Encrypter {
public:
  unordered_map<char, string> encDict;
  unordered_map<string, int> decDict;
  
  Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
    for(int i=0; i<keys.size(); i++) {
      encDict[keys[i]] = values[i];
    }
    for(auto i:dictionary) {
      string tmp = encrypt(i);
      if(tmp.size())
        decDict[tmp]++;
    }
  }

  string encrypt(string word1) {
    string encrypted = "";
    for(auto i:word1) {
      if(encDict[i]=="") return "";
      encrypted += encDict[i];
    }
    return encrypted;
  }

  int decrypt(string word2) {    
    return decDict[word2];
  }
};