class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int digitCount[10];
        bool present[900];
        for(int i=0; i<10; i++) digitCount[i] = 0;
        for(int d: digits) digitCount[d] += 1;
        for(int num = 100; num<1000; num++){
            int d0 = (num % 100)%10;
            int d10 = (num % 100) / 10;
            int d100 = num / 100;
            int reqDigits[10];
            for(int i=0; i<10; i++) reqDigits[i] = 0;
            reqDigits[d0]++;reqDigits[d10]++;reqDigits[d100]++;
            bool possible = true;
            for(int i=0;i<10;i++){
                if(digitCount[i]>=reqDigits[i]) reqDigits[i]--;
                else{
                possible = false;
                break;
                } 
            }
            present[num-100] = possible;
        }
        vector <int> ans;
        for(int i=0; i<900; i++){
            if(!(i%2) && present[i]) ans.push_back(i+100);
        }
        return ans;
    }
};