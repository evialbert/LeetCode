class Solution {
public:
    bool check(unordered_map<char, int> &mpp, int freq){
        for(auto it: mpp){
            if(it.second>=1 && it.second != freq)
                return false;
        }
            
        return true;
    }
    
    bool equalFrequency(string word) {
        unordered_map<char, int> mpp;
        
        for(auto it: word)
            mpp[it]++;
        

        //try removing every char
        for(int i=0; i<word.size(); i++){
            mpp[word[i]]--;      //remove word
            int freq = (i<word.size()-1) ? mpp[word[i+1]]: mpp[word[i-1]];
            // cout<<freq;
            
            if(check(mpp, freq))        //return true if by removing current char frequencies will equal
                return true;
            
            mpp[word[i]]++;     //backtrack
        }
        
        return false;
    }   
};