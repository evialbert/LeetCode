class Solution {
public:
    bool static comp(int a, int b) {
      return a > b;
}
    long long maxWeight(vector<int>& pizzas) {
        long long m  = pizzas.size()/4;
        sort(pizzas.begin(), pizzas.end(),comp);
        int f = 0;
        if(m&1){
            f=1;
        }
        long long mb2 = m /2 , sum = 0;
        for(int i = 0 ;i <mb2 + f ;i++){
            sum += pizzas[i];
        } 
        int t = 0;
        for(int i = mb2 + f + 1;t < mb2 ;i = i+2 ,t++ ){
            sum += pizzas[i];
        } 
        return sum;
    }
};