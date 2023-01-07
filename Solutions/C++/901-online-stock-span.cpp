/*
Problem Title: 901 - Online Stock Span
Lang: C++
Runtime: 656 ms
Memory: 84.5 MB
Problem Url: https://leetcode.com/problems/online-stock-span
Submission Url: https://leetcode.com/problems/online-stock-span/submissions/341802787
*/

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 0;
        while(!st.empty()  and st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }
        st.push({price, ans+1});
        
        return ans+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */