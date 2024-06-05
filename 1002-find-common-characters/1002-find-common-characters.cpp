class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.size() == 1)
        {
            vector<string> res(A[0].size());
            transform(A[0].begin(), A[0].end(), res.begin(), 
                           [](auto c) -> string { return {c}; });
            return res;
        }
                                                   
        unordered_map<char,int> chFreq;
        for(auto ch : A[0]) chFreq[ch]++;
        string curr = "";
        vector<char> answer;
        vector<string> ansStr;
        
        for(int i = 1; i < A.size(); i++){
            unordered_map<char,int> copyFreq(chFreq.begin(), chFreq.end());
            if(answer.size() != 0){
                copyFreq.clear();
                for(auto ch : answer) copyFreq[ch]++;
                answer.clear();
            }
            
            for(auto ch : A[i]){
                if(copyFreq[ch] > 0){
                    answer.push_back(ch);
                    copyFreq[ch]--;
                }
            }
            
            if(answer.size() == 0) break;
        }
        
        for(auto ch : answer){
            curr += ch;
            ansStr.push_back(curr);
            curr = "";
        }
        
        return ansStr;
    }
};