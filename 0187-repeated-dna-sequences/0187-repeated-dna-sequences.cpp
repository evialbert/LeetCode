class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        
        int n = str.size();
        
        // store the frequency of the DNA sequence
        
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            // find DNA sequence of length 10
            
            int j = i;
            
            string DNA = "";
            
            while(j < n && DNA.size() < 10)
            {
                DNA += str[j];
                
                j++;
            }
            
            // push the sequence into map
            
            mp[DNA]++;
        }
        
        vector<string> res;
        
        for(auto x : mp)
        {
            if(x.second > 1)
            {
                res.push_back(x.first);
            }
        }
        
        return res;
    }
};