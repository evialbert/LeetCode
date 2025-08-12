class Solution {
public:
    string concatHex36(int n) {
        string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string hexad = "";
        int temp = n*n; 
        while(temp > 0){
            hexad += base[temp%16];
            temp /= 16;
        }
        ranges::reverse(hexad);
        string hexat = "";
        int temp2 = n*n*n; 
        while(temp2 > 0){
            hexat += base[temp2%36];
            temp2 /= 36;
        }
        ranges::reverse(hexat);
        return hexad + hexat;
    }
}; 