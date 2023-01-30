/*
Problem Title: 2549 - Count Distinct Numbers on Board
Lang: C++
Runtime: 294 ms
Memory: 6.5 MB
Problem Url: https://leetcode.com/problems/count-distinct-numbers-on-board
Submission Url: https://leetcode.com/problems/count-distinct-numbers-on-board/submissions/887149737
*/

class Solution {
public:
    int distinctIntegers(int n) {
        int num = n;
        set<int> st;
        st.insert(n);
        while(num--){
            for(int i=1;i<=n;i++){
                for(auto x : st){
                    if(x%i == 1) {
                        st.insert(i);
                    }
                }
            }
        }
        return st.size();
    }
};