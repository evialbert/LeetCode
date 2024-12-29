class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int largest_idx = 0;
        priority_queue<pair<string,int>> largest;
        for(int i=0;i<word.size();i++){
            if(word[i]>=word[largest_idx]){
                largest.push({word.substr(i),i});
                largest_idx = i;
            }
        }
        largest_idx = largest.top().second;
        
        if(numFriends==word.size()) return word.substr(largest_idx,1);
        
        if(largest_idx+1>=numFriends){
            return word.substr(largest_idx);
        }
        
        int partitions = 0, i = 0;
        priority_queue<string> pq;
        while(pq.size()<numFriends && i<word.size()){
            if(i!=largest_idx){
                pq.push(word.substr(i,1));
                i++;
            }
            else {
                int rem = numFriends-pq.size();
                int len = word.size()-i-rem+1;
                pq.push(word.substr(i,len));
                i += len;
            }
        }
        return pq.top();
    }
};