class Solution {
    public int bitwiseComplement(int N) {
        return (int)Math.pow(2, Integer.toBinaryString(N).length()) - 1 ^ N;
    }
}