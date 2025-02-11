class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {  // Keep removing until part is no longer found
            s.erase(s.find(part), part.size()); 
        }
        return s;
    }
};