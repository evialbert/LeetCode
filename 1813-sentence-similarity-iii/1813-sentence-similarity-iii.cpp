class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 < n2) return areSentencesSimilar(s2, s1);

        int i1 = 0, j1 = n1 - 1;
        int i2 = 0, j2 = n2 - 1;

        while (i2 < n2) {
            int t1 = i1, t2 = i2;
            while (i2 < n2 && s2[i2] != ' ') {
                if (s1[i1] != s2[i2]) break;
                i1 ++;
                i2 ++;
            }

            if (i2 == n2) {
                if ((i1 == n1) || (s1[i1] == ' ')) return true;
                i2 = t2 - 1;
                i1 = t1 - 1;
                break;
            }

            if (s1[i1] != s2[i2]) {
                i1 = t1 - 1;
                i2 = t2 - 1;
                break;
            }
            i1 ++;
            i2 ++;
        }


        while (j2 > i2) {
            int t1 = j1, t2 = j2;
            while (j2 > i2 && s2[j2] != ' ') {
                if (s1[j1] != s2[j2]) return false;
                j1 --;
                j2 --;
            }
            
            if (j1 >= 0 && j2 >= 0 && s1[j1] != s2[j2]) return false;
            if (i2 == j2) return (j1 == -1) || (s1[j1] == ' ');

            if (s1[j1] != s2[j2]) {
                j1 = t1 + 1;
                j2 = t2 + 1;
                break;
            }
            j1 --;
            j2 --;
        }

        //cout<<i2<<" "<<j2<<endl;
        return false;
    }
};