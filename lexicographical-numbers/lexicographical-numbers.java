//Using recursion
class Solution {
    private int num;
    private List<Integer> op;
    public List<Integer> lexicalOrder(int n) {
        this.num = n;
        this.op = new ArrayList<>();
        helper(0);
        return op;
    }
    private void helper(int prevNum) {
        int start = (prevNum>0?0:1);
        for(int i=start;i<=9;i++){
            int curNum = prevNum*10+i;
            if(curNum<=num){
                op.add(curNum);
                helper(curNum);
            }
        }
    }
}