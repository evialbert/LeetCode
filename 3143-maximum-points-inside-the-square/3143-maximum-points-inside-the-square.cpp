class Solution {
    private:
    bool check(const std::vector<std::vector<int>>& points, const std::string& s, int side) {
        vector<bool>hash(26,0);
         for(int i=0;i<points.size();i++){
             if(abs(points[i][0])<=side&&abs(points[i][1])<=side){
                 if(hash[s[i]-'a'])return 0;
                 hash[s[i]-'a']=1;
             }
         }
        return true;
    }
public:
    int maxPointsInsideSquare(std::vector<std::vector<int>>& points, std::string s) {
        int n = points.size();
        int side = 0;
    
        int l = 0, r = 1e9; 
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(points, s, mid)) {
                side = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int ans = 0;
        for(int i=0;i<points.size();i++){
             if(abs(points[i][0])<=side&&abs(points[i][1])<=side){
                ans++;
             }
         }
        
        return ans;
    }   
    

};
