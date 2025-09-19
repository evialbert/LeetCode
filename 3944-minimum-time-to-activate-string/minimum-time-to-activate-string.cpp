class Solution {
public:
    long long int countcombinations(string s,int t){
        long long int count = 0,star = 0,characters = 0,number=0;
        for(int i=0;i<s.length();i++){
            characters++;
            if(s[i] =='*'){
                star++;
                number = (s.length() - i);
                count+=(characters*(number));
                characters = 0;
                if(star==t+1){
                    return count;
                }
            }
        }
        return count;
    }
    int minTime(string s, vector<int>& order, int k) {
        long long int cnt = 0,count = 0;
        int low = 0 , high = order.size()-1;
        int mid = low+(high-low)/2;
        string str = s;
        while(low<=high){
            mid = low+(high-low)/2;
            s = str;
            for(int i=0;i<=mid;i++){
                s[order[i]] = '*';
            }
            cnt = countcombinations(s,mid);
            if(low==high && low == mid){
                if(cnt>=k) return mid;
                return -1;
            }
            count = cnt;
            // cout << mid << " -> " << cnt << endl;
            if(cnt==k) return mid;
            
            if(cnt>k){
                high = mid;
            }
            else low = mid+1;
        }
        if(mid == high && count<k) return -1;
        return mid;
    }
};

// ab*cde*fg

// a 7
// b 7
// * 7
// c 3
// d 3
// e 3
// * 3
// f 
// g 