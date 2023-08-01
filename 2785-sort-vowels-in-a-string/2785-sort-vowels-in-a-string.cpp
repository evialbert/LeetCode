class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e'|| c=='i'  ||c=='o' || c=='u' || c=='A' || c=='E'|| c=='I'  ||c=='O' || c=='U' )return true;
        return false;
    }
    string sortVowels(string s) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:s){
            if(isvowel(it))pq.push(it);
        }
        string ans;
        for(auto it:s){
            if(isvowel(it)){
                ans.push_back(pq.top());
                pq.pop();
            }
            else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};