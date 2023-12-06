class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        int min=0, max=0, ans=0;
        
        while(max<time)
        {
            for(int i=0; i<clips.size(); i++)
            {
                int left=clips[i][0];
                int right=clips[i][1];
                
                if(left <= min && right> max)
                    max=right;
            }
            
            if(min==max)
                return -1;
            
            min=max;
            ans++;
        }
        return ans;
    }
};