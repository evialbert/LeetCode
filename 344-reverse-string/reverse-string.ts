/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
    let i = 0, n = s.length-1;
    while(i < n){
        const val = s[i];
        s[i] = s[n];
        s[n] = val;
        i++;
        n--;
    }
};