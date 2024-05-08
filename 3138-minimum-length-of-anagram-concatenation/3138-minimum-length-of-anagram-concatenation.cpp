class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size() ; 
        vector<vector<int>> freq(26 , vector<int>(n+1 , 0)) ; 
        for(int i = 0 ; i < n ; i++){
            freq[s[i]-'a'][i+1] = 1 ;
            for(int j = 0 ; j < 26 ; j++){
                freq[j][i+1] += freq[j][i] ; 
            }
        }
        for(int j = 1 ; j < n ; j++){ // len of anagram
            if(n%j==0){
                bool flag = true ;
                for(int i = 0 ; i < 26 && flag; i++){
                    for(int k = 1 ; k <= n/j ; k++){
                        if(freq[i][k*j] != k*freq[i][j]){
                            flag = false ; 
                            break ;
                        }
                    }
                }
                if(flag){
                    return j ;
                }
            }
        }
        return n ;
    }
};