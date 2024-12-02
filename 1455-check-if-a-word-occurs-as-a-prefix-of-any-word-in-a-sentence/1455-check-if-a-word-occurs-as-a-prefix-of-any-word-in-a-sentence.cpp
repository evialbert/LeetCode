class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
       vector<string> words{100};
       int j=0;
       for(int i=0;i<sentence.size();i++){
        while(sentence[i]!=' ' && i<sentence.size()){
            words[j]+=sentence[i];
            i++;
        }
        j++;
       }
       cout<<j<<endl;
       for(int i=0;i<j;i++){
        if(searchWord[0]==words[i][0]){
            cout<<words[i]<<endl;
            int k=0;
            while(k<searchWord.size() && k<words[i].size()){
                if(searchWord[k]==words[i][k])
                    k++;
                else    
                    break;
            }
            if(k==searchWord.size())
                return i+1;
        }
       }
       return -1;
    }
};