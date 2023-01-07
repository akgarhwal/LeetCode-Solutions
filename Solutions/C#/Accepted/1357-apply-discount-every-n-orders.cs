/*
Problem Title: 1357 - Apply Discount Every n Orders
Lang: C#
Runtime: 692 ms
Memory: 62.7 MB
Problem Url: https://leetcode.com/problems/apply-discount-every-n-orders
Submission Url: https://leetcode.com/problems/apply-discount-every-n-orders/submissions/305758778
*/

public class Cashier {
    int n, discount;

    int[] products;
    int[] prices;
    int count = 0;
    
    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.n = n;
        this.discount = discount;
        this.products = products;
        this.prices = prices;
    }
    
    public double GetBill(int[] product, int[] amount) {
        double final_amount = 0.0;
        count += 1;
        
        for(int index = 0; index < product.Length; index++){
            
            for(int ind = 0;ind < products.Length; ind++){
                
                if(product[index] == products[ind]){
                    
                    final_amount += ((double)prices[ind] * (double)amount[index]);

                }
                
            }
            
            
        }
        
        if(count == n){
            
            final_amount = final_amount - (discount * final_amount) / 100.0;
            count = 0;
        }
       
        return final_amount;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.GetBill(product,amount);
 */