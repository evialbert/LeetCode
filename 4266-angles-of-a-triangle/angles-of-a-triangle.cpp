class Solution {
public:
    vector<double> internalAngles(vector<int>& S) {
        // Sort 
        sort(S.begin(), S.end());
        double a=S[0], b=S[1], c=S[2];

        // Validate triangle 
        if (a+b<=c) return {};

        // Heron's Formula for Area
        double s=(a+b+c)/2.0;
        double area=s*(s-a)*(s-b)*(s-c);
        area=sqrt(area);

        const double PI=acos(-1.0);
        vector<double> angle(3);

        angle[0]=asin((2.0*area)/(b*c))*180/PI;
        angle[1]=asin((2.0*area)/(a*c))*180/PI;
        angle[2]=180.0-angle[0]-angle[1];

        return angle;
    }
};