class Solution {
    public int mirrorReflection(int p, int q) {
        if(q == 0) return 0;
        int sum = q, temp = q;
        boolean back = false, refl = true;
        while(sum % p != 0) {
            sum += q;
            temp += q;
            refl = !refl;
            if(temp > p) {
                back = !back;
                temp = temp - p;
            }
        }
        if(!back && !refl)
            return 2;
        if(!back && refl)
            return 1;
        return 0;
    }
}