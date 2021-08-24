class Solution {
    public boolean isRationalEqual(String S, String T) {
        return Math.abs(compute(S) - compute(T)) < 1e-9;
    }
    public double compute(String s){
        if (!s.contains("(")){
            return Double.valueOf(s);
        }
        //0.5(25) = 0.5 + 0.025 * (1 + 0.01 + 0.0001 + ...) = 0.5 + 0.025 / (1 - 0.01)
        double nonRepeatingValue = Double.valueOf(s.substring(0, s.indexOf("(")));
        int nonRepeatLength = s.indexOf("(") - s.indexOf(".") - 1;
        int repeatLength = s.indexOf(")") - s.indexOf("(") - 1;
        String repeatValue = s.substring(s.indexOf("(") + 1, s.length() - 1);
        double repeat = Integer.valueOf(repeatValue) / (Math.pow(10, repeatValue.length() + nonRepeatLength));
        double ration = 1.0 / (1 - Math.pow(0.1, repeatLength));
        //Integer.parseInt(s.substring(s.indexOf('(') + 1, s.indexOf(')')));
        return nonRepeatingValue + repeat * ration;
    }
}