public class Solution {
    public int nthUglyNumber(int n) {
        
        int result = 1;
        int array[] = new int[n+1];
        
        int m2 = 0, m3 = 0, m5 = 0;
        array[0] = 1;
        
        for(int i=1; i<n; i++){
            int a = array[m2]*2;
            int b = array[m3]*3;
            int c = array[m5]*5;
            
            array[i] = min(a, b, c);
            
            if(array[i] == a) m2++;
            if(array[i] == b) m3++;
            if(array[i] == c) m5++;
        }
        
        return array[n-1];
        
    }
    
    public int min(int i, int j, int k){
        return ((i<j?i:j)<k)?(i<j?i:j):k;
    }
    
}