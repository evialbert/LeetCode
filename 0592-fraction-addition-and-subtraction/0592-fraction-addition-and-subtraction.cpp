class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denumerator = 1;
        int n = expression.size(), i = 0;

        while(i < n)
        {
            int sign = 1;
            if(expression[i] == '+' || expression[i] == '-')
            {
                if(expression[i] == '-')
                    sign = -1;
                i++;
            }

            int num = 0;
            while(isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            i++;

            int den = 0;
            while(isdigit(expression[i]))
            {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numerator = numerator * den + num * denumerator;
            denumerator *= den;

            int g = gcd(abs(numerator), denumerator);

            numerator /= g;
            denumerator /= g;
        }

        return to_string(numerator) + "/" + to_string(denumerator);
    }

    int gcd(int x, int y)
    {
        if(y == 0)
            return x;
        return gcd(y, x % y);
    }
};