class Solution {
    public int countOperations(int num1, int num2) {
        int operation = 0;
        while(num1 > 0 && num2 > 0){
            operation++;
            if(num1 <= num2) num2 -= num1;
            else num1 -= num2;
        }
        return operation;
    }
}