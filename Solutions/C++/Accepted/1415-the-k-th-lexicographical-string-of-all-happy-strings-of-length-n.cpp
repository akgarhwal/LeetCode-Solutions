/*
Problem Title: 1415 - The k-th Lexicographical String of All Happy Strings of Length n
Lang: C++
Runtime: 96 ms
Memory: 21.9 MB
Problem Url: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
Submission Url: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/submissions/326602538
*/

class Solution {
public:
    
    void genHappyStr(int i, int n, vector<string>& all, string str){
        if(i == n){
            all.push_back(str);
            return;
        }
        char chr[3] = {'a','b','c'};
        
        for(char ch: chr){

                if(i > 0 and str[i-1] != ch){
                    genHappyStr(i+1, n, all, str + ch);
                }
                else if(i == 0){
                    genHappyStr(i+1, n, all, str + ch);
                }

        }
        
    }
    
    string getHappyString(int n, int k) {
        vector<string> all;
        genHappyStr(0, n, all, "");
        
       if( k > all.size()){
           return "";
       }
        
        return all[k-1];
    }
};