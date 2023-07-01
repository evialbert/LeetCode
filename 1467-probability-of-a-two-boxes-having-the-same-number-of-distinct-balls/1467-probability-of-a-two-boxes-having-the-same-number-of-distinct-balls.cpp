class Solution {
public:
    double possible = 0.0;
    double valid = 0.0;
    vector<int> first,second;
    
    double getProbability(vector<int>& balls) 
    {
        first.resize(10,0);
        second.resize(10,0);
        dfs(balls, 0, 0, 0);
        return valid / possible;
    }
    
    void dfs(vector<int>& balls, int num1, int num2, int idx) 
    {
        if (idx == balls.size()) 
        {
            if (num1 == num2) 
            {
                // compute fake permutation
                double distrib = permFake(first) * permFake(second);
                possible += distrib;
                
                // find one valid distribution
                if (unique(first) == unique(second))
                    valid += distrib;
            }
            return;
        }
        
        
        for (int b = 0; b <= balls[idx]; b++) 
        {
            first[idx] = b;
            second[idx] = balls[idx] - b;
            dfs (balls, num1 + first[idx], num2 + second[idx], idx + 1);
        }
    }
    
    // unique colors in 
    int unique(vector<int> &balls) 
    {
        int unique = 0;
        for (int b: balls)
            unique += b > 0 ? 1 : 0;
        return unique;
    }
    
    // return 1 / (b1!b2!b3!...bn!) 
    double permFake(vector<int> &balls) 
    {
        double ret = 1.0;
        for (int b: balls)
            ret /= factorial(b);
        return ret;
    }
    
    int factorial(int n)
    {
        int ret = 1;
        while (n > 0) {
            ret *= n;
            n--;
        }
        return ret;
    }
};