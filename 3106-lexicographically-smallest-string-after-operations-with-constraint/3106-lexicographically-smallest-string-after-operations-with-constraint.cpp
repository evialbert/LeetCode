class Solution {
public:
    string getSmallestString(string s, int k) {
        string smallestString = "";
        int n = s.size(), curr = 0;
        while(curr < n){
            if(k > 0){
                int distance = s[curr] - 'a';
                if( (26 - distance < distance ) && k >= (26 - distance) ){
                    k -= 26 - distance;
                    smallestString += 'a';
                }else{
                    int temp = min(k, distance);
                    k -= temp;
                    smallestString += s[curr] - temp;
                }
            }else{
                smallestString += s[curr];
            }
            curr++;
        }
        return smallestString;
    }
};