// variant using resize
class Solution {
public:
    static string decodeCiphertext(string& encodedText, int rows) {
        if (rows==1) return encodedText;
        const int N=encodedText.size(), cols=N/rows;

        string dec;
        dec.reserve(N);
        for (int start=0; start<cols; start++) {
            for (int r=0, c=start; r<rows && c<cols; r++, c++) {
                dec.push_back(encodedText[r*cols+c]);  
            }
        }
        int sz=dec.size();
        while (!dec.empty() && dec[sz-1]==' ') sz--;
        dec.resize(sz);   

        return dec;
    }
};