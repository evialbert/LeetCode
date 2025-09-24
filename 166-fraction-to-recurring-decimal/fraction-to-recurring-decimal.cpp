class Solution {

    using ll = long long;

public:
    string fractionToDecimal(int numerator, int denominator) {
        
        string res = "";

        //Adding a negative sign if one of the numerator or denominator is -ve
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            res += "-";
        }

        //Map to store the position where the number styarts repeating themselves
        unordered_map<ll, ll> mp;

        ll rem = (1LL*numerator) % denominator;
        ll quot = (1LL*numerator) / denominator;

        res += to_string(abs(quot));

        //If remainder comes to be zero initially then there will be no decimals
        if(rem == 0) {
            return res;
        }


        //Applying long division method for calculation
        //After the deimal place
        rem *= 10;
        res += ".";
        mp[rem] = 0;

        bool isRepeating = false;
        ll cnt = 1;
        ll repPos = 0;
        while(true) {

            quot = rem / denominator;
            rem = rem % denominator;
            
            rem *= 1LL*10;

            res += to_string(abs(quot));

            //If we the remainder starts repeating that means quotient
            //will start repeating themselves
            if(mp.find(rem) != mp.end()){
                repPos = mp[rem];
                isRepeating = true;
                break;
            }

            //If remeainder is zero them no need to process further
            if(rem == 0) {
                break;
            }

            mp[rem] = cnt++;
            
        }

        //String parsing logic for adding brackets for 
        //Repeating sequence
        string ans = res;
        if(isRepeating) {

            ans = "";
            
            ll i = 0;
            while(res[i] != '.') {
                ans += res[i];
                i++;
            }

            ans += res[i];
            i++;

            ll cnt = 0;
            while(i < res.length()) {

                if(cnt == repPos) {
                    ans += '(';
                }

                ans += res[i];
                i++;
                cnt++;
            }

            ans += ")";
        }

        return ans;

    }
};