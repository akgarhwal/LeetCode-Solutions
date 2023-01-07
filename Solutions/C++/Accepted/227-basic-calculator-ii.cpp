/*
Problem Title: 227 - Basic Calculator II
Lang: C++
Runtime: 16 ms
Memory: 9.1 MB
Problem Url: https://leetcode.com/problems/basic-calculator-ii
Submission Url: https://leetcode.com/problems/basic-calculator-ii/submissions/325309838
*/

class Solution {
public:
    int performOps(int x, int y, char op){
        switch(op){
            case '/':
                return x/y;
            case '*':
                return x*y;
            case '-':
                return x-y;
            case '+':
                return x+y;
        }
        return x;
    }
    int calculate(string s) {
        vector<int> numbers;
        vector<char> ops;
        int num = 0;
        for(char ch : s){
            
            if(ch >= '0' && ch <= '9'){
                num = num *10 + (ch - '0');
            }
            else if(ch != ' '){
                ops.push_back(ch);
                numbers.push_back(num);
                num = 0;
            }
        }
        numbers.push_back(num);

        if(ops.size() == 0){
            return numbers[0];
        }
        
        // ops order
        int ops_index = 0;
        
        int res = 0, pval = numbers[0];
        
        while(ops_index < ops.size()){
            
            if(ops[ops_index] == '+' or ops[ops_index] == '-'){
                res = performOps(res, pval, '+');
                pval = ops[ops_index] == '-' ? -1*numbers[ops_index + 1] : numbers[ops_index + 1];
            }
            else{
                pval = performOps(pval,numbers[ops_index+1], ops[ops_index]);
            }
            
            ops_index += 1;
            //cout<<res<<" - "<<pval<<endl;
        }
        res = res + pval;
        
        return  res;
    }
};