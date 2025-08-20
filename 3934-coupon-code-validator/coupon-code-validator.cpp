class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> electronics;
        vector<string> grocery;
        vector<string> pharmacy;
        vector<string> restaurant;
        for (int i = 0; i < n; i++) {
            if (code[i] != "") {
                bool chk = true;
                for (char c : code[i]) {
                    if (!(c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
                        chk = false;
                        break;
                    }
                }
                if (chk == true) {
                    if (businessLine[i] == "electronics" && isActive[i] == true) {
                        electronics.push_back(code[i]);
                    } else if (businessLine[i] == "grocery" && isActive[i] == true) {
                        grocery.push_back(code[i]);
                    } else if (businessLine[i] == "pharmacy" && isActive[i] == true) {
                        pharmacy.push_back(code[i]);
                    } else if (businessLine[i] == "restaurant" && isActive[i] == true) {
                        restaurant.push_back(code[i]);
                    }
                }
            }
        }
        sort(electronics.begin(),electronics.end());
        sort(grocery.begin(),grocery.end());        
        sort(pharmacy.begin(),pharmacy.end());
        sort(restaurant.begin(),restaurant.end());
        vector<string> ans;
        for (int i = 0; i < electronics.size(); i++) {
            ans.push_back(electronics[i]);
        }
        for (int i = 0; i < grocery.size(); i++) {
            ans.push_back(grocery[i]);
        }
        for (int i = 0; i < pharmacy.size(); i++) {
            ans.push_back(pharmacy[i]);
        }
        for (int i = 0; i < restaurant.size(); i++) {
            ans.push_back(restaurant[i]);
        }
        return ans;
        return {};
    }
};