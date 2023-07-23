class Solution {
public:
    bool visited[41][41][2000] = {};
    bool possiblyEquals(string a, string b) {
        return helper(a, b, 0, 0, 0);
    }
    
private:
    bool helper(string& a, string& b, int i, int j, int diff){
        if(i == a.size() && j== b.size()) return diff == 0;
        
        if(visited[i][j][diff + 1000] == false){
            visited[i][j][diff + 1000] = true;
            
            
            //a[i] is digit
            if(i < a.size() && isdigit(a[i])) {
                int val = 0;
                for(int p = i; p < a.size() && isdigit(a[p]); p++){
                    val = val*10 + (a[p] - '0');
                    
                    //Wildcard in string a is given by -ve diff, hence diff-val
                    if(helper(a, b, p+1, j, diff-val)) return true;
                }
                return false;
            }
            
            //b[i] is digit
            if(j < b.size() && isdigit(b[j])) {
                int val = 0;
                for(int p = j; p < b.size() && isdigit(b[p]); p++){
                    val = val*10 + (b[p] - '0');

                    //Wildcard in string b is given by +ve diff, hence diff+val
                    if(helper(a, b, i, p+1, diff+val)) return true;
                }
                return false;
            }
            
            //b had wildcard and hence diff > 0, so move further in a and move diff towards 0
            if(diff > 0) return i<a.size() && helper(a, b, i+1, j, diff-1);
            
            //a had wildcard and hence diff < 0, so move further in b and move diff towards 0
            if(diff < 0) return j<b.size() && helper(a, b, i, j+1, diff+1);
            
            //if both a[i] and b[j] are characters
            return i<a.size() && j<b.size() && a[i] == b[j] && helper(a, b, i+1, j+1, diff);
        }
        return false;
    }   
};