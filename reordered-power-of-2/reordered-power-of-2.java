class Solution {
    public boolean reorderedPowerOf2(int n) {
        int powerOfTwo = 1, digitsAmount = digits(n);
        while(true){
            int curDigits = digits(powerOfTwo);
            if(curDigits == digitsAmount){
                if(arePermutations(powerOfTwo, n))
                    return true;
            }else if(curDigits > digitsAmount)
                break;
            powerOfTwo *= 2;
        }
        return false;
    }
              
    private int digits(int n){
        int cnt = 0;
        while(n > 0){
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    private boolean arePermutations(int num1, int num2){
        int[] count1 = getCount(num1);
        int[] count2 = getCount(num2);
        return equal(count1, count2);
    }

    private int[] getCount(int num){
        int[] res = new int[10];
        if(num == 0)
            res[0] = 1;
        while(num > 0){
            res[num % 10]++;
            num /= 10;
        }
        return res;
    }

    private boolean equal(int[] count1, int[] count2){
        for(int i = 0; i < count1.length; i++){
            if(count1[i] != count2[i])
                return false;
        }
        return true;
    }

}