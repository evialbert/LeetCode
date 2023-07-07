class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int start = 0,end = 0, n = answerKey.length(), count=0, ans = INT_MIN;

        while( end < n )
        {
            if( answerKey[end]=='F')
            {
                count++;
                while( count > k)
                {
                    if( answerKey[start]=='F')
                    {
                        count--;
                    }
                    start++;
                }
            }
            ans = max( ans,end-start+1);
            end++;
        }
        start = 0,end = 0,count=0;
        while( end < n )
        {
            if( answerKey[end]=='T')
            {
                count++;
                while( count > k)
                {
                    if( answerKey[start]=='T')
                    {
                        count--;
                    }
                    start++;
                }
            }
            ans = max( ans,end-start+1);
            end++;
        }
        return ans;
    }
};