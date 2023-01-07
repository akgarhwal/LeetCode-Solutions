/*
Problem Title: 906 - Super Palindromes
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/super-palindromes
Submission Url: https://leetcode.com/problems/super-palindromes/submissions/490698602
*/

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long ll = CI(left), rl=CI(right);
        int ans = 0;
        for(int i = 0; i <=9; i++) {
            genP(to_string(i), ans, ll, rl);
        }
        genP("", ans, ll, rl);
        return ans.size();
    }
    
    void genP(string x, int &ans, long ll, long rl) {
        if(x.size() >= 10) return;
        
        long n = CI(x);
        if(n > INT_MAX){
            return;
        }
        long nn = n*n;
        
        if(nn > rl) {
            return;
        }
        // if(x.size() > 1 and x[0] == '0')
        //     cout<<x<<endl;
        
        if( nn >= ll and nn <= rl and isP(to_string(nn) ) ) {
            ans+=1;
        }
        
        for(int i = 0; i<=9; i++){
            string t = to_string(i) + x + to_string(i); 
            if(isP(t)){
                genP(t, ans, ll, rl);
            }
        }
    }
    bool isP(string x){
        int l = x.size();
        for(int i = 0 ; i < l/2;i++){
            if(x[i] != x[l-1-i]){
                return false;
            }
        }
        return true;
    }
    long CI(string x){
        long n = 0;
        for(char ch : x){
            n = n*10 + (ch - '0');
        }
        return n;
    }
};