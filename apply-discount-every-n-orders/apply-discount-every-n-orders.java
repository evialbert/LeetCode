class Cashier {
int pos = 1;
int n = 0, discount = 0;
Map<Integer, Integer> map = new HashMap<>();
public Cashier(int n, int discount, int[] products, int[] prices) {
    this.n = n;
    this.discount = discount;
    for(int i = 0; i < products.length; i++)
    {
        map.put(products[i], prices[i]);
    }
}

public double getBill(int[] product, int[] amount) {
    double total = 0;
    for(int i = 0; i < product.length; i++)
    {
        total += map.get(product[i])*amount[i]*1.0;
    }
    
    if(pos%n == 0)
    {
        total = total*((100-discount)*(1.0)/100.0);
    }
    
    pos++;
    return total;
}
}