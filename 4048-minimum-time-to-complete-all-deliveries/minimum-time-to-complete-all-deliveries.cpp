class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        int d1= d[0], r1= r[0];
        int d2= d[1], r2= r[1];

        // lcm of r1 and r2
        int lcm= (r1 * r2) / __gcd(r1 , r2);

        // equation (1)
        long long x= ceil((d1 + d2) * 1ll * lcm * 1.0 / (lcm - 1));

        // equation (2)
        long long y= ceil(d1 * 1ll * r1 * 1.0 / (r1 - 1));

        // equation (3)
        long long z= ceil(d2 * 1ll * r2 * 1.0 / (r2 - 1));

        // Taking maximum of all values in maxT
        long long maxT = max({x , y , z});


        return maxT - 1;
    }
};